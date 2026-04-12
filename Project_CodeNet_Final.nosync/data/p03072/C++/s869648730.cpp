#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=n; i--)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
#define v2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll N;
ll H[25];
ll ans;
int main() {
	cin >> N;
	REP(i,0,N) cin>>H[i];
	REP(i,0,N){
		bool ok=true;
		REP(j,0,i){
			if(H[j] > H[i]){
				ok=false;
				break;
			}
		}
		if(ok) ans++;
	}
	p(ans);
	return 0;
}
