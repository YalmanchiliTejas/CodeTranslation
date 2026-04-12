#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;


int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ll ans=0, sum=0, sqr=0;
	int N;
	cin >> N;
	vl v(N);
	for(auto&q : v) cin >> q, sum+=q, sum%=MOD, sqr+=(q%MOD)*(q%MOD), sqr%=MOD;

	ans=(sum*sum-sqr);
	if(ans%2!=0) ans+=MOD;
	ans/=2;
	ans%=MOD;
	
	cout << ans << "\n";
	return 0;
}
