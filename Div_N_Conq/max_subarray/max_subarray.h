#ifndef _MAX_SUBARRAY_H
#define _MAX_SUBARRAY_H 1
/*
 *	low <= high
 *	sum holds sum of elements between low and high of an array
 */
#define TYPE int
struct max_subarray_solution {
	int low;
	int high;
	TYPE sum;
};


struct max_subarray_solution *find_max_crossing_subarray(TYPE A[],int low,int mid,int high);
struct max_subarray_solution *find_max_subarray(TYPE A[],int low,int high);

#endif
