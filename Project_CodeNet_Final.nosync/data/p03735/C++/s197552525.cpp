#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MX = 200005;
const int MM = 1000000007;

int N, a, b;
int rl = 1e9, rr, bl = 1e9, br;
pii D[MX];

ll solve()
{
	sort(D+1, D+N+1);
	int mx = 1;
	for(int i = 2; i <= N; i++) if( D[mx].second < D[i].second ) mx = i;
	if( 1 == mx ) return 2e18;
	swap(D[mx], D[2]);
	sort(D+3, D+N+1);
	multiset<int> L; L.insert(D[1].second); L.insert(D[2].first);
	ll mn = 2e18;
	for(int i = 3; i <= N; i++){
		L.insert(D[i].first);
	}
	mn = min(mn, (ll)*L.rbegin() - *L.begin());
	for(int i = 3; i <= N; i++){
		L.erase(L.find(D[i].first));
		L.insert(D[i].second);
		mn = min(mn, (ll)*L.rbegin() - *L.begin());
	}
	return mn * (D[2].second - D[1].first);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d%d", &a, &b);
		if( a > b ) swap(a, b);
		D[i] = pii(a, b);

		rl = min(rl, a);
		rr = max(rr, a);
		bl = min(bl, b);
		br = max(br, b);
	}
	printf("%lld\n", min(solve(), (ll)(rr-rl) * (br-bl)));
}
