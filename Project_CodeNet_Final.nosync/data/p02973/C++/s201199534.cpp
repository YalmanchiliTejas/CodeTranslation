#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<ll> V(n, -1); cin >> V[0];
    

    rept(i, 1, n){
        int a; cin >> a;
        int ng = -1, ok = n;
        while(ok - ng > 1){
            int mid = (ng + ok) / 2;
            if(V[mid] < a) ok = mid;
            else ng = mid;
        }
        V[ok] = a;
    }
    int res = 0;
    rep(i, n){
        if(V[i]==-1)break;
        res++;
    } 
    cout << res << ln;
}
