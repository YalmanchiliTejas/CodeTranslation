#include <bits/stdc++.h>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

long long firsttime[100010]={};
long long sums[100010];
void solve(long long N, long long X, long long M){
  long long A=X;
  firsttime[A]=1;
  sums[0]=0;
  sums[1]=A;
  long long K=min(N,100010LL);
  long long i=2;
  for(;i<=K;i++){
    A=(A*A)%M;
    sums[i]=sums[i-1]+A;
    if(firsttime[A]!=0){
      break;
    }
    firsttime[A]=i;
  }
  if (i==N+1){
    cout<<sums[N]<<endl;
    return;
  }
  long long loop_begin=firsttime[A];
  long long loop_length=i-loop_begin;
  long long loop_count=(N-(loop_begin-1))/loop_length;
  //cout<<i<<" "<<A<<" "<<loop_length<<" "<<loop_count<<endl;
  //cout<<sums[i]-sums[loop_begin]<<endl;
  long long result=(sums[i]-sums[loop_begin])*loop_count;
  long long j=N-loop_length*loop_count;
  //cout<<j<<endl;
  result+=sums[j];
  cout<<result<<endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long X;
  scanf("%lld",&X);
  long long M;
  scanf("%lld",&M);
  solve(N, X, M);
  return 0;
}
