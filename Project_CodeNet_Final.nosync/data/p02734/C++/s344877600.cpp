#include <stdio.h>
int A[3001],d[3001],M=998244353,i,K,N,S,j,P;
int main(){scanf("%d%d",&N,&S);while(i++<N)scanf("%d",&A[i]);while(--i){j=S+1;P=A[i];while(j--){d[j]+=(j>=A[i]?d[j-P]:0)+(j==P);d[j]%=M;}K=(K+d[S])%M;d[0]++;}printf("%d\n",K);}