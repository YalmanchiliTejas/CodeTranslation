#include<bits/stdc++.h>
using namespace std;

using Int = long long;
using ll = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b)a=b;};
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b)a=b;};

template<typename T> void drop(T x){cout<<x<<endl;exit(0);};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll s,t,p,q,m,y;
  cin>>s>>t>>p>>q>>m>>y;

  cout<<(t^s^y)<<endl;
  return 0;
}

