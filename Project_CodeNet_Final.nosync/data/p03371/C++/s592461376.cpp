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

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;


    int ans = A*X+B*Y;
    REPS(buy_mix, max(X, Y)){
        ans = min(ans, buy_mix*2*C+max(X-buy_mix, 0)*A+max(Y-buy_mix, 0)*B);
    }
    cout << ans << endl;

    return 0;
}