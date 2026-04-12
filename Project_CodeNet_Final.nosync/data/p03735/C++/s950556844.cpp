#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPS(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#define REVERSE(i,n) for(int (i) = n-1;(i) >= 0 ; --i)
#define ALL(c) (c).begin() , (c).end()
#define LL long long
#define int LL
#define inf  (1LL << 60)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lower lower_bound
#define upper upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n
#define pl(a) cout << ""#a": " << a << endl;
#ifdef _DEBUG
#define debug_io fstream cin("input.txt");ofstream cout("output.txt");
#else
#define debug_io ;
#endif
#define debug_input debug_io
#define DOWN(T) std::greater<T>()
template<class T>void scan(vector<T>& a, int n, istream& cin)
{
	T c; REP(i, n) { cin >> c; a.push_back(c); }
}
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>;
using psi = pair<string, int>; using vvi = vector<vi>; using pss = pair<string, string>;
using vpii = vector<pii>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

bool ed[200001];

signed main()
{
	QUICK_CIN;
	debug_input;

	int n;
	cin >> n;
	vpii balls;
	vpii aballs;
	REP(i, n) {
		int c, d;
		cin >> c >> d;
		balls.push_back({ c,d });
		aballs.push_back({ c,i });
		aballs.push_back({ d,i });
	}
	vi r, b;
	REP(i, n) {
		r.push_back(max(balls[i].first, balls[i].second));
		b.push_back(min(balls[i].first, balls[i].second));
	}
	sort(ALL(r));
	sort(ALL(b));

	int cand1 = (r.back() - r[0])*(b.back() - b[0]);

	sort(ALL(aballs));
	int rc = aballs.back().first - aballs[0].first;

	set<pii> select;
	int min_d = inf;
	REP(i, n) {
		select.insert({ min(balls[i].first,balls[i].second),i });
	}
	REP(i, n) {
		min_d = min(min_d, select.rbegin()->first - select.begin()->first);
		auto it = select.begin()->second;
		select.erase(select.begin());
		select.insert({ max(balls[it].first ,balls[it].second),it });
	}

	cout << min(cand1, rc*min_d) << endl;

}