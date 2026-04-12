#include <bits/stdc++.h>
using namespace std;
#define int long long

// typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

// rep
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
#define DEBUG(x) cerr << #x << ": " << x << '\n'
#define DEBUGP(x) cerr << #x << ": " << x.first << " \t" << x.second << '\n'

string s;

signed main()
{
    cin >> s;

    int cnt_a = 0;
    int cnt_b = 0;
    REP(i, 3){
        if (s[i] == 'A') cnt_a++;
        if (s[i] == 'B') cnt_b++;
    }

    if (cnt_a == 3 || cnt_b == 3) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}