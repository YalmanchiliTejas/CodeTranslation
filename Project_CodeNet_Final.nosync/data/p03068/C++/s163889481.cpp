#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int max(int a,int b){return (a>b ? a:b);}
int min(int a,int b){return (a<b ? a:b);}

int compare_int(const void *a, const void *b){return *(int*)a - *(int*)b;}
//これは昇べきの順のソート

//int compare_int(const void *a, const void *b){return *(int*)b - *(int*)a;}
//これは降べきの順のソート

//qsort(配列, 長さ, sizeof(int), compare_int);

double BS(int array[],int len,int target);


void merge(long long a1[],long long len_a1,long long a2[],long long len_a2,long long a[]){
    long long i = 0,j = 0;
    while(i<len_a1 || j<len_a2){
        if(j>=len_a2 || (i<len_a1 && a1[i]<a2[j])){
            a[i+j] = a1[i];
            i++;
        }else{
            a[i+j] = a2[j];
            j++;
        }
    }
}
void mergeSort(long long a[],long long len_a){
    if(len_a > 1){
        long long m = len_a/2;
        long long n = len_a - m;
        long long a1[m];
        long long a2[n];
        for(long long i = 0;i < m;i++) a1[i] = a[i];
        for(long long i = 0;i < n;i++) a2[i] = a[m+i];
        mergeSort(a1,m);
        mergeSort(a2,n);
        merge(a1,m,a2,n,a);
    }
}
 
//////////////////////////////////////////


int N,K;
char S[11];

int main(){
    scanf("%d",&N);
    scanf("%s",S);
    scanf("%d",&K);
    
    char mark = S[K-1];

    for(int i = 0;i < N;i++){
        if(S[i] != mark){
            S[i] = '*';
        }
        printf("%c",S[i]);
    }
    printf("\n");

    return 0;
}



///////////////////////////////////////////


double BS(int array[],int len,int target){ //(配列,長さ,見つける値)
    int low,mid,high;

    low = 0;
    high = len-1;

    int mark;

    while(low <= high){
        mid = (low + high) / 2;
        if(array[mid] == target){
            mark = 0;
            break;
        }else if(array[mid] < target){
            low = mid + 1;
            mark = 1;
        }else{
            high = mid - 1;
            mark = -1;
        }
    }
    if(mark == 0){
        return mid; //配列の何番目か（０から）
    }else if(mark == 1){
        return (double)mid + 0.5;//なかったらどこのあいだか
    }else{
        return (double)mid - 0.5;
    }
}
