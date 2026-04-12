#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m; cin>>n>>m;
	vector<string> in(n);
	vector<bool> a(n,false),b(m,false);
	For(i,0,n-1){
		cin>>in[i];
		For(j,0,m-1){
			if(in[i][j]=='#'){
				a[i]=true; b[j]=true;
			}
		}
	}
	For(i,0,n-1){
		For(j,0,m-1){
			if(a[i] && b[j]) cout<<in[i][j];
		}
		if(a[i])cout<<"\n";
	}
	return 0;
}



























