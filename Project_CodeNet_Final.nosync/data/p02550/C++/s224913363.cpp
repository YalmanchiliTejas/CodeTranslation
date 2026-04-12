#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) ;

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N, X, M; cin >> N >> X >> M;
	vector<ll> his;
	vector<bool> is(100000+10, false);

	ll res{0};
	ll m{-1};
	REP(i, N)
	{
		if (is[X])
		{
			m = X;
			break;
		}
		else
			is[X] = true;
		res += X;
		his.push_back(X);
		(X *= X) %= M;
	}

	if (m == -1)
	{
		std::cout << res << std::endl;
		return 0;
	}

	vector<ll> hiss;
	ll it = find(ALL(his), m) - his.begin();
	for (ll i = it; i < his.size(); ++i)
	{
		hiss.push_back(his[i]);
		DEBUG(his[i]);
	}

	ll rem = N - it;
	DEBUG(rem);
	ll sum = accumulate(ALL(hiss), 0ll);
	DEBUG(sum);
	ll cs = hiss.size();
	DEBUG(cs);
	res += sum * (rem/cs -1);
	res += accumulate(hiss.begin(), hiss.begin()+(rem%cs), 0ll);
	
	std::cout << res << std::endl;
	return 0;
}
