#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

ll b[55], p[55], l[55];

int main(int argc, char const *argv[])
{
	int n; ll x; cin >> n >> x;
	b[0] = 0; p[0] = 1; l[0] = 1;
	rep(i, n) {
		b[i + 1] = 2 * b[i] + 2;
		p[i + 1] = 2 * p[i] + 1;
		l[i + 1] = b[i + 1] + p[i + 1];
	}

	ll sum = 0, sump = 0;
	for (int i = n; i >= 1; --i) {
		rep(j, 5) {
			if (j == 0) {
				if (sum + 1 > x) {
					break;
				}
				sum++;
			} else if (j == 1) {
				if (sum + l[i - 1] > x) {
					break;
				}
				sum += l[i - 1];
				sump += p[i - 1];
			} else if (j == 2) {
				if (sum + 1 > x) {
					break;
				}
				sum++; sump++;
			} else if (j == 3) {
				if (sum + l[i - 1] > x) {
					break;
				}
				sum += l[i - 1];
				sump += p[i - 1];
			} else {
				if (sum + 1 > x) {
					break;
				}
				sum++;
			}
		}
		if (sum == x) break;
	}

	printf("%lld\n", sump);

	return 0;
}