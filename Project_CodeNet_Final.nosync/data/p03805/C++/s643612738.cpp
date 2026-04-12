#include <bits/stdc++.h>
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    cin.tie(0);
    ios::sync_with_stdio(false);<- これら、printfとかと併用しない方が良さそう

*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n==0) return 1;
    ll res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;
    else return res*res%mod*x%mod;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };


// 線分 ab の偏角 返り値は[-π, π]
double argument(const pair<double, double> &a, const pair<double, double> &b){
    double ax=a.first, ay=a.second, bx=b.first, by=b.second;
    return atan2(by-ay, bx-ax);
}

/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */

int N, M;
vector<vector<int>> adj;
vector<bool> seen;

void input(){
    cin >> N >> M;
    adj.resize(N, vector<int>());
    seen.resize(N, false);
    rep(i, M){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int dfs(int i){
    if(all_of(seen.begin(), seen.end(), [](auto val){ return val == true; })) return 1;

    int res = 0;
    for(auto j : adj[i]){
        if(seen[j] == false){
            seen[j] = true;
            res += dfs(j);
            seen[j] = false;
        }
    }

    return res;
}

void solve(){
    seen[0] = true;
    cout << dfs(0) << endl;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    input();
    solve();
    
    return 0;
}