#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAX_M = 100000;
int find_num[MAX_M+1] = {};

ll f(ll n, ll x, ll m){
    ll ans = 0;
    for(ll i=0; i<n; ++i){
        ans += x;
        x = (x*x)%m;
    }
    return ans;
}

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    if(n<=MAX_M){
        cout << f(n, x, m);
        return 0;
    }
    ll y = x;
    int cnt = 1;
    while(find_num[y] == 0){
        find_num[y] = cnt;
        cnt++;
        y = (y*y)%m;
    }
    // 周期
    const int interval = cnt - find_num[y];
    const ll interval_sum = f(MAX_M+interval, x, m) - f(MAX_M, x, m);
    const ll interval_num = (n-MAX_M)/interval;
    const ll remain_num = n - interval_num * interval;
    cout << interval_sum * interval_num + f(remain_num, x, m);
    return 0;
}
