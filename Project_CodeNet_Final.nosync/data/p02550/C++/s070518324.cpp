#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn = 1e5 + 5;
const int mod = 998244353;
int vis[maxn];
ll a[2 * maxn];
int main()
{
    ios::sync_with_stdio(false);
    ll n , x , m; cin >> n >> x >> m;
    a[1] = x;
    vis[a[1]] = 1;
    ll l = n + 1 , r = n;
    for (int i = 2 ; i <= n ; i++){
        a[i] = (a[i - 1] * a[i - 1]) % m;
        if (vis[a[i]]) {
            l = vis[a[i]];
            r = i - 1;
            break;
        }
        vis[a[i]] = i;
    }
  //  cout << l << " " << r << endl;
    ll ans = 0 , len = r - l + 1;
    for (int i = 1 ; i <= r ; i++){
        ans += a[i];
    }
    ll sum = 0;
    for (int i = l ; i <= r ; i++) sum += a[i];

    ll rest = n - r , cnt = (len == 0 ? 0 : rest / len);
    ans += sum * cnt;
    ll last = (len == 0 ? 0 : (rest % len));
    for(int i = 0 ; i < last ; i++) ans += a[l + i];
    cout << ans << endl;
  //  cout << 492443256176507ll - ans << endl;
    return 0;
}