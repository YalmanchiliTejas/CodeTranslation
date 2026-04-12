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

	ll N, M;
	cin >> N >> M;

	if (N == M)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	//system("pause");
}
