#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <iostream>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
/*vector<Type> v;
vector<Type> v();
vector<Type> v(n);
vector<Type> v(n, d);
vector<vector<Type>> vv;
vector<vector<Type>> vv();
vector<vector<Type>> vv(n);
vector<vector<Type>> vv(n, vector<Type>(m));
vector<vector<Type>> vv(n, vector<Type>(m, d));*/


int main() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  long long Asum=0;
  long long mod = pow(10,9)+7;
  rep(i,N){
    cin>>A[i];
    Asum+=A[i];
    Asum%=mod;
  }
  long long sum=0;
  for(int i=0;i<N-1;i++){
    Asum-=A[i]%mod;
    if(Asum<0) Asum+=mod;
    sum+=(A[i]*Asum)%mod;
    sum%=mod;
  }
  cout<<sum;
  return 0;
}
