#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <stack>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(998244353)
#define INF 1e12
#define int ll
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

int pos(int n,int k,vector<int> &v){
	int hi=n,lo=-1;
	while(hi-lo>1){
		int m=(hi+lo)/2;
		if(v[m]<=k) lo=m;
		else hi=m;
	}
	return hi;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin>>n;
	vector<int> v(n+1,INF);
	int t;
	For(i,0,n-1){
		cin>>t;
		v[pos(n,-t,v)]=-t;
	}
	cout<<pos(n,INF-1,v)<<"\n";
	return 0;
}















