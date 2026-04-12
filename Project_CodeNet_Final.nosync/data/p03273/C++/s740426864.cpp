#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    rep(i, h)rep(j, w) cin >> a[i][j];

    vector<bool> flag_h(h, false);
    vector<bool> flag_w(w, false);

    rep(i, h)rep(j, w) if(a[i][j] == '#') flag_h[i] = true;
    rep(i, w)rep(j, h) if(a[j][i] == '#') flag_w[i] = true;

    rep(i, h){
        if(!flag_h[i]) continue;
        rep(j, w){
            if(flag_w[j]) cout << a[i][j];
        }
        cout << endl;
    }
}