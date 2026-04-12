#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
//using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dh[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dw[8] = {1, -1, 0, 1, -1, 0, 1, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
using Graph = vector<vector<int>>;
Graph G;
  
/*------------------------------------------------------------------*/
ll kaijou(ll l, ll m){
    ll re = 1;
    while(m > 0){
        re *= l;
        m--;
    }
    return re;
}

ll dfs(ll n, ll x){
    if(n == 0) return 1;  
    if(x == 1) return 0;

    ll layer = kaijou(2, n + 1) - 3;
    ll patty = kaijou(2, n) - 1;

    if(1 < x and x <= layer + 1) return dfs(n - 1, x - 1);
    else if(x == 2 + layer) return patty + 1;
    else if(2 + layer < x and x <= 2 * layer + 2){
        return patty + 1 + dfs(n - 1, x - layer - 2);
    }else if(x == 2 * layer + 3) return 2 * patty + 1;
}

int main(){
    ll n, x; cin >> n >> x;
    cout << dfs(n, x) << endl;
}