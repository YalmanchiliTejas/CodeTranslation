#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = (int)1e9 + 7;
signed main(){
    int n; cin >> n;
    int sum = 0;
    int ans = 0;
    vi v(n);
    rep(i, 0, n) {
        cin >> v[i];
        sum += v[i];
    } 
    rep(i, 0, n) {
        ans += (((sum - v[i]) % mod ) * v[i]) % mod; 
        sum -= v[i];
        ans %= mod;
    }
    cout << ans;

}