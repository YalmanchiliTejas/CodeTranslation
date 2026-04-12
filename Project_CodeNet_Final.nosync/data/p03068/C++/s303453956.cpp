#include <bits/stdc++.h>
using namespace std;

#define dlog(str) cout << "====" << str << endl;
#define INF 999999999
#define MOD 1000000007
#define REP(i, n) for(int i = 0, i##_l = (n); i < i##_l; i++)
#define FOR(i, s, e) for(int i = s, i##_l = (e); i < i##_l; i++)
#define LLI long long int
#define _min(a, b) ((a < b) ? a : b)
#define _max(a, b) ((a < b) ? b : a)
#define chmax(a, b) a = _max(a, b)
#define chmin(a, b) a = _min(a, b)
#define bit(a, shift) ((a>>shift)&1))
#define pm(a) ((a) ? 1 : -1)
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort((v).rbegin(), (v).rend())
// int 2.14E±9    lli 9.2E±18    double 1.7E±380

int main() {
    int N, K;
    string s;
    cin >> N >> s >> K;
    char comp = s[K - 1];
    REP(i, s.size()) {
        if(s[i] != comp) {
            s[i] = '*';
        }
    }
    cout << s;
    return 0;
}