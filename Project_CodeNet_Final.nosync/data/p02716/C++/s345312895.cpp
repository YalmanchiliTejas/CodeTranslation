#include <bits/stdc++.h>
#define ll long long
#define MAX 500005
#define INF ((ll)1e17)
using namespace std;

ll n, ans = -INF;
ll a[MAX], sum[MAX][3], mx[MAX], ss[MAX];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    if(!(n&1)){
        ll s = 0;
        for(int i = 1; i <= n; i += 2) s += a[i];
        ans = max(ans, s);
        s = 0;
        for(int i = 2; i <= n; i += 2) s += a[i];
        ans = max(ans, s);
        for(int i = 1; i <= n; i += 2){
            ss[i] = ss[max(i-2, 0)]+a[i];
        }
        for(int i = n; i >= 2; i -= 2){
            ss[i] = ss[i+2]+a[i];
        }
        for(int i = 1; i <= n; i += 2){
            ans = max(ans, ss[i]+ss[i+3]);
        }
        cout << ans << endl;
        return 0;
    }
    for(int i = 1; i <= n; i += 2) sum[i][1] = sum[max(i-2, 0)][1]+a[i];
    ll s = 0;
    for(int i = n-1; i >= 2; i -= 2) s += a[i+1], sum[i][0] = sum[i+2][0]+a[i], mx[i] = s-sum[i][0];
    for(int i = n-1; i >= 2; i -= 2){
        mx[i] = max(mx[i], mx[i+2]);
    }
    for(int i = 1; i <= n; i += 2){
        ans = max(ans, sum[max(i-2, 0)][1]+sum[i+1][0]+mx[i+1]);
    }
    cout << ans << endl;

    return 0;
}