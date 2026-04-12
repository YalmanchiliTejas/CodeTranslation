#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
int MOD = 1000000007; 

int main(){
  int n; cin >>n;
  vector<ll>a(n),b(n),sum(n+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=n-1;i>=0;--i){
    sum[i]+=a[i]+sum[i+1];
    sum[i]%=MOD;
    //cout<<sum[i]<<endl;
  }
  ll kotae=0;
  for(int i=0;i<n-1;i++){
    kotae+=a[i]*sum[i+1];
    kotae%=MOD;
    //cout<<a[i]<<" "<<sum[i+1]<<endl;
  }
  cout<<kotae<<endl;
  return 0;
}

