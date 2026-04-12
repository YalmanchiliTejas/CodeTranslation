#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using numr=std::numeric_limits<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y ;
    int ab = 2*c;
    int ans = INF;
    for(int i = 0; i<=max(x,y); i++){
        int cost = ab*i + a*max(0,x-i) + b*max(0,y-i);
        if(ans>cost) ans = cost;
    }
    cout << ans << endl;
}