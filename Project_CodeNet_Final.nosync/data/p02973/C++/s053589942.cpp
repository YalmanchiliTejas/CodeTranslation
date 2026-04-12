#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define VI vector<int>
#define PII pair<int, int>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
const int INF=1<<30; const ll LINF=1LL<<60 ; const ll mod=1e9+7 ;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//-------------------
int n;
ll a[100000+5];
//ll dp[100000+5];
//bool check[100000+5];

int main(){
	scanf("%d", &n);
	FOR(i,1,n){ ll x; scanf("%lld", &x); a[i] = -x;}
	vector<ll> v(n,LINF);
	FOR(i,1,n){
		//cout << a[i];
		int idx = upper_bound(ALL(v), a[i]) - v.begin();
		v[idx] = a[i];
	}
	int ans = 0;
	FOR(i,0,n-1){
		ans += (v[i] != LINF? 1:0);
	}
	cout << ans << endl;
    return 0;
}
