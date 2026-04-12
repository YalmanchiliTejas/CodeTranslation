#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define allr(v)				((v).rbegin()), ((v).rend())
#define sz(v)				((int)((v).size()))
#define ll long long
#define pb					push_back
#define fIO ios_base::sync_with_stdio(0);cin.tie(0);

const ll oo = 1e8;
const double pi = 3.1415926535897;


const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


typedef vector<int>                vi;
typedef vector<pair<int,int>>      vii;
typedef vector<ll>                 vll;
typedef vector<double>             vd;
typedef vector< vi >               vvi;
typedef vector< vd >               vvd;
typedef vector<string>             vs;
typedef pair<int, int>             pii;

/**
    * PLEASEEE READDD PROBLEEEM CARFULLY ****
    * Always check for OVERFLOW ll vs int
    * Always check for array bounds
    * Check for function return
    * READ OUTPUT SECTION AGAIN!!!
**/

struct edge{
    int from, to, w;

    edge(){}
    edge(int x, int y, int we): from(x), to(y), w(we){}

    bool operator < (const edge &rhs) const{
        return w > rhs.w;
    }

};

const int N = 3000 + 5;

ll dp[N][N][3];
ll a[N];
int n;

ll sol(int l, int r, int turn) {
    if(l == r) return (turn == 1 ? a[l] : -a[l]);

    ll &ret = dp[l][r][turn];
    if(ret != -1) return ret;

    if(turn) ret = max(a[l] + sol(l + 1, r, 1 - turn), a[r] + sol(l, r - 1, 1 - turn));
    else ret = min(sol(l + 1, r, 1 - turn) - a[l], sol(l, r - 1, 1 - turn) - a[r]);

    return ret;
}
int main(){
    fIO

//    freopen("", "r", stdin);
//    freopen("", "w", stdout);

    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    cout << sol(0, n - 1, 1);
}






