#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector < ll > vl;
typedef vector < int > vi;
typedef vector < bool > vb;
typedef vector < vl > vvl;
typedef vector < vi > vvi;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < pll > vpll;
typedef vector < pii > vpii;
typedef vector < vpll > vvpll;
typedef vector < vpii > vvpii;

#define pb push_back
#define eb emplace_back
#define pf push_front
#define all(c) (c).begin(), (c).end()
#define ff first
#define ss second
#define mp(x,y) make_pair((x), (y))
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)



void solve(){
    
    int n; cin >> n;
    cout << (n >= 30 ? "Yes" : "No") << '\n';
    
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    boost;

    int t = 1;
    // cin >> t;


    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";

        solve();

    }
    return 0;
}