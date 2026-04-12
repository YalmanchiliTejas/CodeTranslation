
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("O3")  
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define F first
#define pii pair<int,int>
#define S second
#define endl "\n"
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define mem(z,i) memset(z,i,sizeof(z))
#define eps 1e-7
#define I (int)
#define mod 1000000007
#define pb push_back
const long long INF = 1000000000000000000LL;
//const int WASTE=∞
const int N=1e5+5;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  	// cout<<fixed;
  	// cout.precision(10);
   	// ofstream cout (".out");
    // ifstream cin  (".in");
    #define int ll
	ll n,X,m;
	cin>>n>>X>>m;
	vector<int>v;
	int z[N]; mem(z,-1);
	v.pb(X); z[X]=0;
	int sp;
	for(int x=1;x<=n;x++){
		X=((X%m)*(X%m))%m;
		if(z[X]>-1){
			sp=z[X]; break;
		}
		z[X]=x; v.pb(X);
	}
	ll ans=0,sz=v.size();
	int ps[sz]; ps[0]=v[0];
	for(int x=1;x<sz;x++) ps[x]=ps[x-1]+v[x];
	if(n<=sz){
		ans=ps[I n-1]; cout<<ans;
		return 0;
	}
	else ans+=ps[sp-1];
	int len=n-sp,l=sz-sp;
	ans+=len/l*(ps[sz-1]-ps[sp-1]);
	len%=l;
	ans+=ps[sp+len-1]-ps[sp-1];
   	// int lll=n-sp;
   	// ans+=lll/(nn-sp)*(ps[nn-1]-ps[sp-1]);
   	// ans+=ps[sp+(lll%(nn-sp))]-ps[sp-1];
   	cout<<ans;
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
  	return 0;
}

