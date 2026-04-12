#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
int n;
ll a[N], f[N][N];

ll dp(int l, int r){
    if (l > r) return 0;
    if (f[l][r]) return f[l][r];
    return (f[l][r] = max(a[l] + min(dp(l+1,r-1), dp(l+2,r)),
                          a[r] + min(dp(l+1,r-1), dp(l,r-2))));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
  //  freopen("Deque.inp", "r", stdin);
  //  freopen("Deque.out", "w", stdout);
    cin >> n;
    ll sum = 0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    ll x = dp(1,n);
    ll y = sum - x;
    cout <<x - y;
}
