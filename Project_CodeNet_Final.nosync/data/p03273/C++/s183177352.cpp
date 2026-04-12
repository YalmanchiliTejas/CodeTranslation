#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << std::setprecision(9);
    cout << std::fixed;

    ll h,w;
    cin >> h >> w;
    vector<vector <char> > a;
    char x;

    F0R(i,h){
      bool whiteRow = true;
      std::vector<char> temp;
      F0R(j,w){
        cin >> x;
        temp.pb(x);
        if(x == '#') whiteRow = false;
      }
      if(!whiteRow)
        a.pb(temp);
    }

    F0Rd(i,w){
      bool whiteCol = true;
      F0R(j,sz(a)){
        if(a[j][i] == '#')
          whiteCol = false;
      }

      if(whiteCol)
        F0R(j,sz(a))
          a[j].erase(a[j].begin()+i);
    }
    F0R(i,sz(a)){
      F0R(j,sz(a[0])){
        cout << a[i][j];
      }
      cout << endl;
    }
    return 0;
}

// read the question correctly (ll vs int)
// template by super1 derived from bqi343
