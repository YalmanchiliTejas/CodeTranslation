#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 200003

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  ll sum=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    sum+=A[i];
  }
  sum%=MOD;
  sum=sum*sum%MOD;
  for(int i=0;i<N;i++){
    sum+=A[i]*(MOD-A[i]);
    sum%=MOD;
  }
  sum*=(MOD+1)/2;
  sum%=MOD;
  cout<<sum<<endl;
}
