#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int inf = 1000000007;
const ll linf  = 1ll * inf * inf;
const int N = 50 + 7;
const int M = 31;
const int multipleTest = 0;

string s;

void solve() {
    cin >> s;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            puts("Yes");
            return;
        }
    }
    puts("No");
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
//        printf("Case #%d: ", i + 1);
        solve();
    }
#ifdef _LOCAL_
    cout<<"\n" << 1.0 * clock() / CLOCKS_PER_SEC <<endl;
#endif
}
