#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<cstring>
#include<cctype>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;

const ll INF = 1ll<<29;
const ll MOD = 1000000007;

int m, n;
bool leave[1123];
int next[1123];

int nex(int x) {
	if (leave[next[x]]) return next[x];
	return next[x] = nex(next[x]);
}

int main()
{
	while (cin >> m >> n, m || n) {
		memset(leave, -1, sizeof(leave));
		REP(i, m) next[i] = (i + 1) % m;
		
		int p = 0, cnt = m;
		FOR(t, 1, n + 1) {
			string s; cin >> s;
			if (cnt == 1) continue;
			
			bool ok = true;
			if (t % 15 == 0) {
				if (s != "FizzBuzz") ok = false;
			}
			else if (t % 5 == 0) {
				if (s != "Buzz") ok = false;
			}
			else if (t % 3 == 0) {
				if (s != "Fizz") ok = false;
			}
			else {
				bool f = true;
				REP(i, s.size()) if (!isdigit(s[i])) f = false;
				if (!f) ok = false;
				else {
					int num = atoi(s.c_str());
					if (num != t) ok = false;
				}
			}
			
			if (!ok) { leave[p] = false; cnt--; }
			if (cnt != 0) p = nex(p);
		}
		
		vector<int> ans;
		REP(i, m) if (leave[i]) ans.push_back(i + 1);
		REP(i, ans.size()) printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
}


// 5