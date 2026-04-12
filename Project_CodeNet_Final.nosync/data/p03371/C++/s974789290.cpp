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
    ll a, b, c; cin >> a >> b >> c;
    ll x, y; cin >> x >> y;
    ll n = max(x, y);
    ll ans = 0;
    ll ans_min = INFINITY;
    for(int i = 0; i <= n; i++){
        ll _x = max(0LL, x - i);
        ll _y = max(0LL, y - i);
        ans = 2 * c * i + a * _x + b * _y;
        ans_min = min(ans, ans_min);
    }
    cout << ans_min << endl;
}