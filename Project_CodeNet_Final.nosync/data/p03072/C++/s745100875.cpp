#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <tuple>
#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <functional>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iomanip>

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> H(N);
	for (ll i = 0; i < N; ++i) cin >> H[i];

	ll ans = 0;

	for (ll i = 0; i < N; ++i)
	{
		bool flag = true;

		for (ll j = 0; j < i; ++j)
		{
			if (H[j] > H[i])
			{
				flag = false;
				break;
			}
		}

		if (flag) ans++;
	}

	cout << ans << endl;

	//system("pause");
}