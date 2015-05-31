#ifndef _MAX_SUBARRAY_H
#include "max_subarray.h"
#endif
/*
 * #ifndef _STDLIB_H_
#include<stdlib.h>
#endif
#ifndef _STDIO_H_
#include<stdio.h>
#endif
*/
struct max_subarray_solution *find_max_crossing_subarray(TYPE A[],int low,int mid,int high){
	struct max_subarray_solution *temp = (struct max_subarray_solution*)malloc(sizeof(struct max_subarray_solution ));
	temp->sum=-99999;
	int sum=0;
	int i;
	for(i=mid ; i>=low ; i-- ){
		sum += A[i];
		if (sum > temp->sum ){
			temp->sum=sum;
			temp->low=i;
		}
	}
	sum=0;
	TYPE right_sum=-99999;
	for (i=mid+1 ; i<= high; i++ ){
		sum +=A[i];
		if ( sum > right_sum ){
			right_sum =sum;
			temp->high=i;
		}
	}
	temp->sum += right_sum;

	return temp;
}
struct max_subarray_solution *find_max_subarray( TYPE A[],int low,int high){
	struct max_subarray_solution *temp,*left,*right,*cross;

	if( high == low ){
		temp=(struct max_subarray_solution*) malloc(sizeof(struct max_subarray_solution));
		temp->sum=A[low];
		temp->low=low;
		temp->high=high;
		return temp;
	}else{
		int mid = (low+high)/2;
		left=find_max_subarray( A , low,mid);
		right=find_max_subarray( A ,mid+1 ,high);
		cross=find_max_crossing_subarray( A,low ,mid,high );

		if( ( left->sum >= right->sum ) &&  ( left->sum >= cross->sum ) ){
			free(right);
			free(cross);
			return left;
		}
		else if( ( right->sum >=left->sum ) && ( right->sum >= cross->sum ) ){
			free(left);
			free(cross);
			return right;
		}else{
			free(left);
			free(right);
			return cross;
		}
	}
}
/*
 * test
int main(){
	int A[]={12,-22,11,3,-1,4,-25,-14,1,-16};
	struct max_subarray_solution *ans=find_max_subarray(A,0,9);
	printf("%d %d %d",ans->low,ans->high,ans->sum);
	free(ans);
	return 0;
}
*/
