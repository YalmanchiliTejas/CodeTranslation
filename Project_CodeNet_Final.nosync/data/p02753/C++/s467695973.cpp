#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X,i) ((X>>i)&1)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(rall(a))
#define ina(x,n) rep(x_i,n) cin>>x[x_i]
#define outa(x,n) rep(x_i,n) cerr<<x[x_i]<<" \n"[x_i==n-1]

using ll  = long long int;
using vl  = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

const int inf = (1<<28);
const ll infl = (1LL<<60);
const int mod = 1e9+7;

int main() {
    string s; cin >> s;
    if (s == "AAA" || s == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
