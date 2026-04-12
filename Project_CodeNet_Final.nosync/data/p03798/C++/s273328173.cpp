#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)

void solve(void){
    int N; string S;
    cin >> N >> S;
    string cand[] = {"SS", "SW", "WW", "WS"};
    rep(4, c) {
        string ans = cand[c];
        rep(N-2, i) {
            if ((S[i+1] == 'o' && ans[i+1] == 'S') || (S[i+1] == 'x' && ans[i+1] == 'W')) ans += ans[i];
            else ans += (ans[i]=='S'?"W":"S");
        }
        bool ok = false;
        if (ans[N-1] == 'S') {
            if ((S[N-1] == 'o' && ans[0] == ans[N-2]) || (S[N-1] == 'x' && ans[0] != ans[N-2])) {
                if (ans[0] == 'S') {
                    ok = (S[0] == 'o' && ans[1] == ans[N-1]) || (S[0] == 'x' && ans[1] != ans[N-1]);
                }
                else {
                    ok = (S[0] == 'x' && ans[1] == ans[N-1]) || (S[0] == 'o' && ans[1] != ans[N-1]);
                }
            }
        }
        else {
            if ((S[N-1] == 'x' && ans[0] == ans[N-2]) || (S[N-1] == 'o' && ans[0] != ans[N-2])) {
                if (ans[0] == 'S') {
                    ok = (S[0] == 'o' && ans[1] == ans[N-1]) || (S[0] == 'x' && ans[1] != ans[N-1]);
                }
                else {
                    ok = (S[0] == 'x' && ans[1] == ans[N-1]) || (S[0] == 'o' && ans[1] != ans[N-1]);
                }
            }
        }
        if (ok) {
            cout << ans << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(void){
  solve();
  //cout << "yui(*-v・)yui" << endl;
  return 0;
}
