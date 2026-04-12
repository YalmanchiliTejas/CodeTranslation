#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int max_h = 0;
    int ans = 0;
    REP(i, n) {
        int h;
        cin >> h;
        if(h >= max_h) {
            ans++;
            max_h = h;
        }
    }
    cout << ans << ln;
    return 0;
}
