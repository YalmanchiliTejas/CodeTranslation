#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int bisect_right(int x,int a[],int left,int right){
    int mid;
    right++;
    while (left < right) {
        mid = (left + right) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(void){
    int N;int len = 0;
    scanf("%d", &N); 
    int *array  = (int *)malloc(10E5+10 * sizeof(int));
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x); x *= -1;
        int index  = bisect_right(x,array,0,len -1);
        if (index == len) {
            array[len] = x;
            len++;
        } else {
            array[index] = x;
        }
    }    
    printf("%d\n",len);
    free(array);
}
