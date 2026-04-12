/***********************************************************
	When you are inspired by passion 
	and you want to live for the current moment

	When your every thought and action
	has the power to become the story of your future

	When difficulties stand to demolish your Glory
	Just remember that Life is a 'Golden adverse Story'

	Withstand it to acheive your passion and dreams
	more amazingly more easily.

	Why then? When writing the story of your Life
	You want to Let someone else hold your pen

					huzaifa242©

***********************************************************/
#include "bits/stdc++.h"
using namespace std;
#define int int64_t
#define MAX 100005
#define x first 
#define y second

int seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l = 0, int r = numeric_limits <int>::max())
{return uniform_int_distribution<int> (l, r)(rng);}

template <typename T, typename G>
ostream& operator << (ostream& out, const pair <T, G> &a) 
{return out << "( " << a.x << ", " << a.y << ")";}

template <typename T>
ostream& operator << (ostream& out, const vector <T> &a) 
{out << "[ "; for(const auto &i: a) out << i << ", "; return out << "]" << endl;}

template <typename T>
ostream& operator << (ostream& out, const set <T> &a) 
{out << "{ "; for(const auto &i: a) out << i << ", "; return out << "}" << endl;}

template <typename T, typename G>
ostream& operator << (ostream& out, const map <T, G> &a) 
{out << "< "; for(const auto &i: a) out << i << ", "; return out << ">" << endl;}

template <typename T, size_t N>
typename enable_if<!is_same <typename remove_cv <T>::type, char>::value,
ostream&>::type operator << (ostream& out, T (&a)[N])
{out << "[ "; for(const auto &i: a) out << i << ", "; return out << "]" << endl;}

void debug_out(){cerr << endl;} 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{cerr << (H) << ' '; debug_out(T...);}
 
#ifdef LOCAL
#define debug(...) cerr << '#' << #__VA_ARGS__ << ":\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 24
#endif

int mod = 998244353;
int md(int x, int mdo = mod) {
	x %= mdo;
	return x < 0? x + mdo: x;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, x, m, sum = 0, rem;
	cin >> n >> x >> m;
	mod = m;
	rem = n;
	vector <int> edge(m, 0);
	pair <int,int> cyc = {-1, -1};
	int cyc_sum = 0, cur;
	for (int i = 1; i <= n; ++i) {
		sum = sum + x;
		rem--;
		if (edge[x]) {
			cyc = {edge[x], i - 1};
			cur = x;
			sum -= x;
			rem++;
			for (int j = edge[x]; j < i; ++j) {
				cyc_sum = cyc_sum + cur;
				cur = md(cur * cur);
			} 
			break;
		}
		edge[x] = i;
		x = md(x * x);
	}
	if (cyc != pair <int,int> (-1, -1)) {
		int complete = rem / (cyc.y - cyc.x + 1);
		rem -= (complete * (cyc.y - cyc.x + 1));
		sum = sum + complete * cyc_sum;
		for (int i = 0; i < rem; ++i) {
			sum = sum + cur;
			cur = md(cur * cur);
		}
	} 
	cout << sum << '\n';
	return 0;
}
