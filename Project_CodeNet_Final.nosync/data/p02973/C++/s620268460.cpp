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

int main(int argc, char **argv)
{
	cin >> N;
	vector<ll> A(N);
	REP(i, N) cin >> A[i];
	vector<ll> s;
	REP(i, N)
	{
		ll t = A[i];
		auto itr = lower_bound(s.rbegin(), s.rend(), t);
		if (itr == s.rbegin())
			s.push_back(t);
		else
			*(itr-1) = t;
		
	}
	std::cout << s.size() << std::endl;
}
