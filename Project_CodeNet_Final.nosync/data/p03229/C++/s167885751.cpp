#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
template<class T> inline istream& operator >> (istream & c, vector<T> & A) {rep(i, A.size()) c >> A[i];return c;}
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;
	sort(a.begin(), a.end());
	int pos1 = 0, pos2 = n - 2;
	bool turn = true;
	deque<int> deq;
	deq.push_back(a[n - 1]);
	while (pos1 <= pos2) {
		if (turn) {
			if (pos1 <= pos2) {
				deq.push_back(a[pos1]);
				pos1++;
			}
			if (pos1 <= pos2) {
				deq.push_front(a[pos1]);
				pos1++;
			}
			turn = false;
		}
		else {
			if (pos1 <= pos2) {
				deq.push_back(a[pos2]);
				pos2--;
			}
			if (pos1 <= pos2) {
				deq.push_front(a[pos2]);
				pos2--;
			}
			turn = true;
		}
	}
	reverse(a.begin(), a.end());
	deque<int> deq2;
	pos1 = 0, pos2 = n - 2;
	turn = true;
	deq2.push_back(a[n - 1]);
	while (pos1 <= pos2) {
		if (turn) {
			if (pos1 <= pos2) {
				deq2.push_back(a[pos1]);
				pos1++;
			}
			if (pos1 <= pos2) {
				deq2.push_front(a[pos1]);
				pos1++;
			}
			turn = false;
		}
		else {
			if (pos1 <= pos2) {
				deq2.push_back(a[pos2]);
				pos2--;
			}
			if (pos1 <= pos2) {
				deq2.push_front(a[pos2]);
				pos2--;
			}
			turn = true;
		}
	}
	ll res1 = 0, res2 = 0;
	/*for (int c : deq) cout << c << ' ';
	cout << endl;*/
	rep(i, deq.size() - 1) {
		res1 += abs(deq[i + 1] - deq[i]);
		res2 += abs(deq2[i + 1] - deq2[i]);
	}
	cout << max(res1, res2) << endl;
	return 0;
}