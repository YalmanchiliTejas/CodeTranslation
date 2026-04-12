#include <bits/stdc++.h>   
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string Yes[2] = {"Yes", "No"};
     
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

using Graph = vector<vector<int>>;
Graph G;

/*------------------------------------------------------------------*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, m; cin >> n >> x >> m;
    vector<ll> a(m + 2);
    vector<ll> sum(m + 2);
    vector<pair<bool,int>> seen(m + 2);
    a[0] = sum[0] = 0;
    a[1] = x;
    sum[1] = x;
    int bef_loop, aft_loop;
    for(int i = 1; i <= m; i++){
        seen[a[i]] = {true, i};
        a[i + 1] = (a[i] * a[i]) % m;
        if(seen[a[i + 1]].first){
            bef_loop = seen[a[i + 1]].second;
            aft_loop = i;
            break;
        }
        sum[i + 1] = sum[i] + a[i + 1];
        if(i + 1 == n){
            cout << sum[i + 1] << endl;
            return 0;
        }
        if(a[i + 1] == 0){
            cout << sum[i] << endl;
            return 0;
        }
    }
    //cout << bef_loop << " " << aft_loop << endl;
    ll ans = 0;
    ans += sum[bef_loop - 1];
    ll loop_num = n - bef_loop + 1;
    ll len = aft_loop - bef_loop + 1;
    ans += (sum[aft_loop] - sum[bef_loop - 1]) * (loop_num / len) + sum[bef_loop - 1 + loop_num % len] - sum[bef_loop - 1];
    cout << ans << endl;
}
