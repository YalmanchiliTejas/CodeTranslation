
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(z, x, y) for(int z=x;z<=y;++z)
#define repd(z, x, y) for(int z=x;z>=y;--z)
typedef long long ll;
const int maxn = (ll) 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
long a[maxn];

int main() { 
	start;
	int n;cin>>n;
	long long sum = 0,ans = 0 ;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		sum %= mod;
	}
	rep(i,0,n-1){
		sum -= a[i];
		if(sum<0) sum += mod;
		ans += sum*a[i];
		ans %= mod;
	}
	
	cout<<ans;
	
	return 0; 
}