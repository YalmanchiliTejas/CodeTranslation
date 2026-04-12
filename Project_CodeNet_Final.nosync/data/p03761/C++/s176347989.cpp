#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const LL mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    VVI v(n, VI(26, 0));
    REP(i, n) {
        string S;
        cin >> S;
        REP(j, S.size()) v[i][S[j]-'a']++;
    }
    
    REP(i, 26) {
        int m = v[0][i];
        REP(j, n) {
            m = min(m, v[j][i]);
        }
        REP(j, m) cout << (char)('a'+i);
    }
    cout << endl;
}