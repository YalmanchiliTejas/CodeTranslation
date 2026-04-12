#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

const ll inf = -1e18;

const int SZ = (1 << 18);

struct starry_sky_tree {
    ll all[SZ * 2], ma[SZ * 2];

    void init() {
        memset(all, 0, sizeof(all));
        memset(ma, 0, sizeof(ma));
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = max(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
    }

    ll get(int a, int b, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) {
            return ma[k] + all[k];
        }

        ll lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        ll rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lc, rc) + all[k];
    }
} seg;

const int MX = 200010;

ll dp[MX];
vector<pii> vadd[MX];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	rep(i, M) {
		int l, r, a;
		scanf("%d %d %d", &l, &r, &a);
		vadd[l].eb(r, a);
	}

	multiset<pair<int, pii>> st;
	seg.init();

	ll ans = 0LL;

	for (int i = 1; i <= N; ++i) {
		while (st.size()) {
			auto it = st.begin();
			if (it->fi < i) {
				seg.add(0, it->se.fi, -(it->se.se));
				st.erase(it);
			} else {
				break;
			}
		}

		for (auto t : vadd[i]) {
			st.insert(mp(t.fi, mp(i, t.se)));
			seg.add(0, i, t.se);
		}

		dp[i] = seg.get(0, i);
		ans = max(ans, dp[i]);

		seg.add(i, i+1, dp[i]);
	}

	cout << ans << endl;

	return 0;
}