#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=r-1;i>=(int)(l);--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using ll=long long;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int mod = 1e9 + 7;

bool path[10][10];

signed main()
{
	int N, M;
	cin >> N >> M;

	rep(i, M) {
		int a, b; cin >> a >> b;
		--a, --b;
		path[a][b] = path[b][a] = true;
	}

	vi arr;
	rep(i, N) arr.PB(i);

	int ans = 0;

	do {
		if (arr[0] != 0) continue;
		bool f = true;

		rep(i, N - 1) {
			if (not path[arr[i]][arr[i + 1]]) {
				f = false;
			}
		}

		ans += f;
	} while (next_permutation(all(arr)));

	cout << ans << endl;
}

