#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 2e5 + 5;
int n;
struct Box {
	int vals[2], pos[2];
} b[N];
struct Ball {
	int val, box, ballID;
	bool operator<(const Ball &rhs) const { return val < rhs.val; }
};
vector<Ball> v;
int other[N << 1];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	fw (i, 0, n) {
		fw (j, 0, 2) {
			cin >> b[i].vals[j];
			v.pb({b[i].vals[j], i, j});
		}
	}
	sort(v.begin(), v.end());
	int curPos = 0;
	fa (i, v) {
		int boxInd = i.box;
		fw (j, 0, 2) if (i.ballID != j) {
			b[boxInd].pos[j] = curPos;
		}
		curPos++;
	}
	fw (i, 0, n) {
//		cout << b[i].pos[0] << " " << b[i].pos[1] << "\n";
		other[b[i].pos[0]] = b[i].pos[1];
		other[b[i].pos[1]] = b[i].pos[0];
	}
	//Case 1: Both min and max are assigned to the same color.
	int bestSuf = -1;
	bw (i, v.size(), 0) if (other[i] > i) {
		bestSuf = i + 1;
		break;
	}
	int ans = infll;
	fw (i, 0, v.size()) {
		if (other[i] < i) break; //Prefix is now invalid.
		bestSuf = max(bestSuf, other[i] + 1);
		if (bestSuf == v.size()) break; //Suffix is now empty. Invalid for current case.
		//If we assign everything from 0 -> i to blue, bestSuf -> sz - 1 is the largest blue suffix.
		//Pair i + 1 and bestSuf - 1 together.
//		cout << "Prefix " << v[i].val << " other = " << other[i] << " bestSuf = " << bestSuf << "\n";
		assert(i + 1 != bestSuf - 1);
		if (other[i + 1] != bestSuf - 1) {
			ans = min(ans, (v.back().val - v[0].val) * (v[bestSuf - 1].val - v[i + 1].val));
		} else {
			//Pair i + 1 with bestSuf.
			if (bestSuf != v.size() - 1) {
				ans = min(ans, (v.back().val - v[0].val) * (v[bestSuf].val - v[i + 1].val));
			}
		}
	}
	//Case 2: Min and max got different colors on 'em.
	//Have min = blue and max = red, then coloring is easy
	int mnBlue = inf, mxRed = -1, mxBlue = -1, mnRed = inf;
	fw (i, 0, n) {
		int small = inf, big = -1;
		fw (j, 0, 2) {
			small = min(small, b[i].vals[j]);
			big = max(big, b[i].vals[j]);
		}
		mxBlue = max(mxBlue, small);
		mnRed = min(mnRed, big);
		mnBlue = min(mnBlue, small);
		mxRed = max(mxRed, big);
	}
	ans = min(ans, (mxBlue - mnBlue) * (mxRed - mnRed));
	cout << ans;
	return 0;
}