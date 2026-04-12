#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
#define ALL(x) x.begin(), x.end()
#define LL long long
#define ULL unsigned long long
#define TIME cout << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << endl;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
    char c;
    cin >> c;

    for(auto i : {'a', 'e', 'i', 'o', 'u'})
        if(c == i) {
            cout << "vowel" << endl;
            return 0;
        }
    cout << "consonant" << endl;

	return 0;
}