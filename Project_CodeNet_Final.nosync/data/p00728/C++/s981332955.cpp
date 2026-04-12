#include <stdio.h>

struct data {int score[100],n;} table[20];
struct data *d;

void sort(int *a,int n){
  int i,j,t;
  for(i=0; i<n-1; i++) for(j=n-1; j>i; j--)
  if(a[j-1]>a[j]) {t=a[j-1]; a[j-1]=a[j]; a[j]=t;}
}

int main(){
  int i,j,N,ave;
  for(i=0;; i++) {d=&table[i];
    scanf("%d",&d->n );
    if(d->n==0) break;
    for(j=0; j<d->n; j++) scanf("%d",&d->score[j] ); }
    N=i;
    for(i=0; i<N; i++) {d=&table[i];ave=0;
      sort(d->score,d->n);
      for(j=1; j<d->n-1; j++) ave+=d->score[j];
      ave/=d->n-2;
      printf("%d\n",ave);}
    }