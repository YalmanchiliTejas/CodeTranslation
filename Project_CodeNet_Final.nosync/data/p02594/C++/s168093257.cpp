#include <bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define rep(i,n)    FOR(i,0,n)
#define rrep(i,n)   for(int i=n-1;i<=0;--i)
#define loop        while(true)
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const ll MAX = 10000000;
const ll MIN = 0;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using pint = pair<int, int>;
using pstring = pair<int, string>;

int main() {
    ll ans;
    ll N;
    cin >> N;
    if(N >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
