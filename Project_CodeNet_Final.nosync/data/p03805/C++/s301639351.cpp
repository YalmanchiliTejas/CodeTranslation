#pragma region Macros
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<(n); i++)
#define REPS(i, n) for(int i=0; i<=(n); i++)
#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define FORS(i, a, b) for(int i=a; i<=(b); i++)
// for container x
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#pragma endregion

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i];

    vector<int> ord(n);
    iota(ALL(ord), 1);

    int ans = 0;
    do {
        bool all_ok = true;
        REP(i, n-1) {
            bool ok = false;
            if (ord[i] < ord[i+1]) {
                REP(j, m) if (a[j]==ord[i] && b[j]==ord[i+1]) ok=true;
            }
            else {
                REP(j, m) if (a[j]==ord[i+1] && b[j]==ord[i]) ok=true;
            }
            if (ok) continue;
            else {
                all_ok=false;
                break;
            }
        }
        if (all_ok) ans++;
    } while(next_permutation(ord.begin()+1, ord.end()));
    cout << ans << endl;
    return 0;
}