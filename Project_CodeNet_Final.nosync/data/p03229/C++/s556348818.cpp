#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=998244353;


int main(){
  ll N,A[100000];
  cin>>N;
  for (int i(0);i<N;i++) cin>>A[i];
  sort(A,A+N);
  if (N%2==0){
    ll tmp(0ll);
    tmp+=A[N/2];
    tmp-=A[N/2-1];
    for (int i(0);i<N/2-1;i++){
      tmp-=2*A[i];
    }
    for (int i(N/2+1);i<N;i++){
      tmp+=2*A[i];
    }
    cout << tmp << endl;
  }else{
    ll tmp(0ll);
    for (int i(N/2+1);i<N;i++){
      tmp+=2*A[i];
    }
    tmp-=(A[N/2]+A[N/2-1]);
    for (int i(0);i<N/2-1;i++){
      tmp-=2*A[i];
    }

    ll tmp2(0ll);
    for (int i(0);i<N/2;i++){
      tmp2-=2*A[i];
    }
    tmp2+=(A[N/2]+A[N/2+1]);
    for (int i(N/2+2);i<N;i++){
      tmp2+=A[i]*2;
    }
    cout << max(tmp,tmp2) << endl;
  }
  return 0;
}
