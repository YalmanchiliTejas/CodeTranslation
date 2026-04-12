
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;


/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    VL a(n);
    FOR(i,0,n-1) {
        cin >> a[i];
    }
    
    ll ans = 0;
    
    bool found;
    do {
        found = false;
    
        FOR(i,0,n-1) if (a[i] >= n) {
            found = true;
            
            ll here = a[i] / n;
                        
            ans += here;
            a[i] %= n;
        
            FOR(j,0,n-1) if (j != i) {
                a[j] += here;
            }
        }
    } while (found);
    
    cout << ans;

    return 0;
}

/*************************************************************************/
