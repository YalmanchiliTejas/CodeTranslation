
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 	
int mod=1e9+7;
int po(int x,int y,int m)  { if (y==0) return 1; int t=po(x,y/2,m)%m; t=(t*t)%m; if (y&1) return (t*x)%m;	return t%m; }

signed main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	int n;
   	cin>>n;
   	vector<int> v(n),tmp(n+1);
   	int ans=0;
   	for (int i=0;i<n;++i)
   		cin>>v[i];
   	for (int i=n-1;i>0;--i)
   		tmp[i]=(tmp[i+1]+v[i])%mod;
   	for (int i=1;i<n;++i){
   		ans=(ans%mod+(tmp[i]*v[i-1])%mod)%mod;
   	}
	cout<<ans<<endl;
   	return 0;
}