#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N;
vector<ll> A;
int main(int argc, char **argv)
{
	cin >> N;
	A.resize(N);
	REP(i, N) cin >> A[i];

	deque<ll> que;
	REP(i, N)
	{
		ll t = A[i];
		ll idx = lower_bound(ALL(que), t) - que.begin();
		if (idx == 0) que.push_front(t);
		else que[idx-1] = t;
	}

	std::cout << que.size() << std::endl;
}
