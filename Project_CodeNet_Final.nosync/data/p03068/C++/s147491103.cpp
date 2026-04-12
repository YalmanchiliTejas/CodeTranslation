#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
int main(int argc, char const *argv[]) {
    int n, k;
    string s;
    cin >> n >> s >> k;
    --k;
    char x = s[k];
    REP(i,n) {
        if (s[i] != x) {
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}