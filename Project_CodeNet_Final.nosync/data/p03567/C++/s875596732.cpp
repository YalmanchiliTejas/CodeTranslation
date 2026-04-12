#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(x, arr) for(auto& x:arr)
#define ITR(x, c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;
typedef pair<int, int> P;

string s;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> s;
	bool ok = false;
	FOR(i, s.size()-1) {
		if (s.substr(i, 2) == "AC") ok = true;
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}