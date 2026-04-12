#include<stdio.h>

typedef int value_type; /* ソートするキーの型 */

value_type med3(value_type x, value_type y, value_type z)
/* x, y, z の中間値を返す */
{
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
        if (z < y) return y; else if (x < z) return x; else return z;
}

void quicksort(value_type a[],value_type b[], int left, int right)
/* クイックソート
 * a     : ソートする配列
 * left  : ソートするデータの開始位置
 * right : ソートするデータの終了位置
 */
{
    if (left < right) {
        int i = left, j = right;
        value_type tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]); /* (i+j)/2ではオーバーフローしてしまう */
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[i] < pivot) i++; /* a[i] >= pivot となる位置を検索 */
            while (pivot < a[j]) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i],a[j] を交換 */
            tmp = b[i]; b[i] = b[j]; b[j] = tmp;
            i++; j--;
        }
        quicksort(a,b, left, i - 1);  /* 分割した左を再帰的にソート */
        quicksort(a,b, j + 1, right); /* 分割した右を再帰的にソート */
    }
}


int main(){
  int N,X[200000],B[200000],A[200000];

  scanf("%d",&N);

  for(int i=0;i<N;i++){
    scanf("%d", &X[i]);
    B[i]=i;
  }

  quicksort(X,B,0,N-1);

  for(int i=0;i<N;i++){
    if(i<N/2)
      A[B[i]]=1;
    else
      A[B[i]]=-1;
  }
  for(int i=0;i<N;i++){
    if(A[i]==1)
      printf("%d\n",X[N/2]);
    else
      printf("%d\n",X[N/2-1]);
  }
  return 0;
}
