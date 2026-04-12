#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/
template <typename T>
class StarrySkyTree {
	const int n;
	vector<T> data, lazy;
	void add_sub(int l, int r, int node, int lb, int ub, T val) {
		if (ub <= l || r <= lb) return;
		if (l <= lb && ub <= r) { lazy[node] += val; return; }
		int left = node * 2, right = left + 1;
		add_sub(l, r, left, lb, (lb + ub) / 2, val);
		add_sub(l, r, right, (lb + ub) / 2, ub, val);
		data[node] = min(data[left] + lazy[left], data[right] + lazy[right]);
	}
	T min_sub(int l, int r, int node, int lb, int ub) {
		if (ub <= l || r <= lb) return INF;
		if (l <= lb && ub <= r) return data[node] + lazy[node];
		T vl = min_sub(l, r, node * 2 + 0, lb, (lb + ub) / 2);
		T vr = min_sub(l, r, node * 2 + 1, (lb + ub) / 2, ub);
		return lazy[node] + min(vl, vr);
	}
	int size(int n) {
		return n == 1 ? n : size((n + 1) / 2) * 2;
	}
public:
	StarrySkyTree(int m) : n(size(m)), data(n * 2, 0), lazy(n * 2, 0) {}
	void add(int l, int r, T val) { add_sub(l, r, 1, 0, n, val); }
	T minimum(int l, int r) { return min_sub(l, r, 1, 0, n); }
};

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	string s; cin >> s;
	StarrySkyTree<int> seg(N);
	vi sum(N+1);
	REP(i, N)
	{
		sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
		seg.add(i, i + 1, sum[i+1]);
	}
	set<int> st;
	REP(i, N)
	{
		if (s[i] == ')') st.insert(i);
	}
	REP(i, Q)
	{
		int t; cin >> t;
		t--;
		if (s[t] == '(')
		{
			s[t] = ')';
			st.insert(t);
			seg.add(t, N, -2);
			int flip = *st.begin();
			s[flip] = '(';
			seg.add(flip, N, 2);
			st.erase(flip);
			cout << flip + 1 << endl;
		}
		else if(s[t] == ')')
		{
			s[t] = '(';
			st.erase(t);
			seg.add(t, N, 2);
			int l = 0, r = N;
			while (r - l > 1)
			{
				int mid = (r + l) / 2;
				int tmp = seg.minimum(mid, N);
				if (tmp == 2) r = mid;
				else l = mid;
			}
			int flip = r;
			s[flip] = ')';
			seg.add(flip, N, -2);
			st.insert(flip);
			cout << flip + 1 << endl;
		}
	}
	return 0;
}