#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define int long long
#ifndef FAST_IO
 #define IOS ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#endif
#define ff first
#define ss second
#define endl "\n"
#define all(c) c.begin(),c.end()
template<typename T>void print(T t){for(auto &it:t)cout<<it<<" "; cout<<endl;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
   int n;
   cin>>n;
   vector<int> v(n);
   for(auto &it:v)cin>>it;
   int cnt=0,mx=0;
   for(int i=0;i<n;i++){
	    if(mx<=v[i]){
		  mx=v[i],cnt++;	
		}
	  }
	  cout<<cnt<<endl;
}
int32_t main(){
  IOS;
  solve();
  //debug();
 #ifdef LOCAL_DEFINE
 cerr<<"time elapsed "<<(double)clock()/CLOCKS_PER_SEC<<endl;
 #endif	
}