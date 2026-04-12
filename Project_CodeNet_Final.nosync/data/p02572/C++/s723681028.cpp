#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double PI = 4*atan(1);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
const string YES = "Possible";
const string NO = "Impossible";
#define pb push_back
#define mp make_pair
#define eb emplace_back

const int MAX_N = 2e5+10;
int N;
ll A[MAX_N];

void solve()
{
	ll psum = 0;
	ll ans = 0;
	for(int i=1;i<=N;++i){
		(ans += psum * A[i])%=MOD;
		(psum+=A[i])%=MOD;
	}
	cout<<ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;++i) cin >> A[i];
	solve();
	return 0;
}