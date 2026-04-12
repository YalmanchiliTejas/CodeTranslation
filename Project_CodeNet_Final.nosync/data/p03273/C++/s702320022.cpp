#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    int h,w; cin >> h >> w;
    char a[h][w];
    rep(i,h) rep(j,w) cin >> a[i][j];
    vector<bool> flag_h(h);
    vector<bool> flag_w(w);
    rep(i,h){
        rep(j,w){
        if(a[i][j] == '#') flag_h[i] = true;
        }
    }
    rep(j,w){
        rep(i,h){
        if(a[i][j] == '#') flag_w[j] = true;
        }
    }
    rep(i,h){
        rep(j,w){
        if(flag_h[i] && flag_w[j])cout << a[i][j];
        }
        if(flag_h[i])cout << endl;
    }
    return 0;
}