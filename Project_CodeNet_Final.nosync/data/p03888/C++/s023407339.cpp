#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long double
//template

//main
signed main(){
  int a,b;cin>>a>>b;
  a=1/a;b=1/b;
  a+=b;
  a=1/a;
  cout<<fixed<<setprecision(12)<<a<<endl;
}
