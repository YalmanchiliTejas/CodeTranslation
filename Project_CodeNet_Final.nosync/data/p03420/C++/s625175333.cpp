#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for(ll b = K + 1; b <= N; b++){
        ll c = N / b;
        ans += c * (b - K);
        ll d = N % b;
        ans += max(0LL, d - K + 1);
        if(K == 0) ans--;
    }
    output(ans);
    
    
    
    
    
    return 0;
}
