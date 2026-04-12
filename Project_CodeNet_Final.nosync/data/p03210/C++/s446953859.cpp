#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>
#include<cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = INF+7;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define rep(i,n) FOR(i,0,n)

struct edge{int to,cost;};

void dump_line(ll *b,int n){
	for(int i=0;i<n;i++){
		cout << b[i] << " ";
	}
	cout << "\n";
}

ll mypow(ll x,ll n){
	if(n==0) return 1;
	ll res=mypow(x*x,n/2);
	if(n&1) res=res*x;
	return res;
}

ll mod_pow(ll x,ll n,ll mod){
	if(n==0) return 1;
	ll res=mod_pow(x*x%mod,n/2,mod);
	if(n&1) res=res*x%mod;
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	if(n==7 || n==5 || n==3) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}