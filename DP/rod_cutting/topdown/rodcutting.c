#ifndef _RODCUTTING_TD_H_
#include "rodcutting.h"
#endif

#ifndef _STDIO_H_
#include<stdio.h>
#endif

int memoized_cutrod_aux( int price[], int n , int r[] ){
	int q,i,temp;
	if ( r[n-1] >= 0 )
		return r[n-1];
	if ( n == 0 )
		q = 0;
	else {
		q=INFINITY;
		for ( i=0 ; i < n ; i++){
			temp = price [ i ] + memoized_cutrod_aux(price, n-i,r);
			q= (q > temp ) ? q:temp;
			printf("%d",q);
			}
		r[n-1] = q;
	}
	return q;
}

int memoized_cutrod ( int p[], int n ){
	int r[n],i;
	for(i=0 ; i < n ; i++ )
		r[i]=INFINITY;
	return memoized_cutrod_aux(p , n , r );
}



int main(){
	int price[4]={1,5,8,9};
	printf("Inside main");
	printf("%d",memoized_cutrod(price,4));
	return 0;
}
