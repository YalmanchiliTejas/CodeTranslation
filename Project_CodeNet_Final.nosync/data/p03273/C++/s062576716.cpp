#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long; 
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
//constexpr long long MOD = 998244353LL;
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int h,w; cin>>h>>w;
    vector<string> a(h);
    rep(i,h) cin>>a[i];
    
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    rep(i,h){
        rep(j,w){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    rep(i,h){
        if(row[i]){
            rep(j,w){
                if(col[j]){
                    cout << a[i][j];
                }
            }
        }
        cout << endl;
    }
    return 0;
}