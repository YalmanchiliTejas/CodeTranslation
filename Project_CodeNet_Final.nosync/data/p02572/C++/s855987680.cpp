#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
int a[300000];
LL s[300000];
int main(){
    int n;
    cin>>n;
    LL ss = 0;
    for (int k = 0; k < n; ++k) {
        scanf("%d", a + k);
        ss += a[k];
        ss %= mod;
        s[k] = ss;
    }
    LL ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += s[i-1] * a[i];
        ans %= mod;
    }
    cout<<ans;
}