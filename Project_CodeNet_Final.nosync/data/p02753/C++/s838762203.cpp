#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, x, y) for(decltype(y) i = (x) - ((x) > (y)); i != (y) - ((x) > (y)); i += 1 - 2 * ((x) > (y)))
#define trav(i,a) for(auto& (i) : (a))
#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define clr(a,x) memset((a),(x),sizeof(a)) // array (0,-1)
#define dbg(x) cerr << "STDERR => " << __LINE__ << ": " << #x << " = " << (x) << "  :(\n";
#define pb push_back
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void cpuTime() { cerr << "cpu time : " << double(clock())/CLOCKS_PER_SEC << "\n"; return; }
using ll = long long;
using ull = unsigned long long;
using F = float;
using D = double;
using vi = vector<int>;
using pii = pair<int,int>;



void solve(){

    string s;
    cin >> s;

    int a = 0, b = 0;
    rep(i,0,3){
        if(s[i] == 'A') ++a;
        else ++b;
    }

    if(!a || !b) cout << "No\n";
    else cout << "Yes\n";
    return;
}

/*
 read the question carefully ( what're the exact constraints? )
 look out for SPECIAL CASES (n=1?) and OVERFLOW (ll vs int?) ARRAY OUT OF BOUNDS
 Check datatypes
*/
int main(){

    fast_io;
    int t=1;
    // cin >> t;

    while(t--){
        solve();
    }

    cpuTime();
return 0;
}
