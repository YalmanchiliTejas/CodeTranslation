#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a, b) accumulate(all(a), b)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
typedef unsigned long long ull;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
ll const INF = 1e18;

template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}



signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    int m = 0, ans = 0;
    for(auto i : v){
        if(i >= m) ans++;
        chmax(m, i);
    }
    cout << ans << endl;

    return 0;
}