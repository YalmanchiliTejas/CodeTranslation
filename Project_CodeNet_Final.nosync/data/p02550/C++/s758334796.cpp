#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) ;
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};



int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, X, M; cin >> N >> X >> M;

	if (N == 1)
	{
		std::cout << X << std::endl;
		return 0;
	}
	
	ll logk{0};
	while ((1ll<<logk) < N) ++logk;

	vector<vector<ll>> ding(logk, vector<ll>(M));
	vector<vector<ll>> ding2(logk, vector<ll>(M));
	REP(i, M)
		ding[0][i] = (i*i)%M;
	REP(k, logk-1)
	{
		REP(i, M)
		{
			ding[k+1][i] = ding[k][ding[k][i]];
		}
	}

	REP(i, M)
		ding2[0][i] = i;
	REP(k, logk-1)
	{
		REP(i, M)
		{
			ding2[k+1][i] = ding2[k][ding[k][i]] + ding2[k][i];
		}
	}

	ll now{X};
	ll res{0};
	--N;
	for (ll bit = 0;; bit++)
	{
		if (N & 1)
		{
			res += ding2[bit][now];
			now = ding[bit][now];
		}
		N = N >> 1;
		if (N == 0)
		{
			res += now;
			break;
		}
	}

	std::cout << res << std::endl;
	return 0;
}
