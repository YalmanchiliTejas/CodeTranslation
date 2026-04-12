#include<bits/stdc++.h>
#define endl '\n';
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,A,B,C,X;
    cin >> N >> A >> B >> C >> X;
    while(N != 0){
        vector<int> Y(N);
        for(int i=0; i<N; i++){
            cin >> Y[i];
        }
        int cnt = 0;
        for(int i=0; i<N; i++){
            bool ok = false;
            for(int j=0; j<C; j++){
                if(X == Y[i]){
                    ok = true;
                    break;
                }
                cnt++;
                X = (A*X+B)%C;
            }
            if(!ok){
                cnt = -1;
                break;
            }
            if(i == N-1) break;
            X = (A*X+B)%C;
            cnt++;
        }
        if(cnt > 10000){
            cout << -1 << endl;
        }else{
            cout << cnt << endl;
        }
        cin >> N >> A >> B >> C >> X;
    }
    return 0;
}
