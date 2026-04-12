#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e7+10;
ll n, x, m, ans;
ll pre[MAX];
unordered_map<ll, int> mp;

int main(){
    scanf("%lld%lld%lld", &n, &x, &m);
    ll op1, op2, t = 0;
    bool flag = false;
    mp[x] = 1;
    pre[1] = x;
    ans = x;
    for (ll i = 2; i <= n; i++){
        x = x * x % m;
        ans += x;
        pre[i] = pre[i-1] + x;
        if (mp[x]){
            flag = true;
            op1 = mp[x];
            op2 = i - 1;
            break;
        }
        mp[x] = i;
    }
    //cout << op1 << " " << op2 << endl;
    //cout << pre[op2] - pre[op1-1] << endl;
    //cout << pre[op1-1] << endl;
    //cout << pre[op1+242]-pre[op1-1] << endl;
    if (flag && x!=0){
        ans = pre[op1-1];
        ll sy = n - (op1 - 1);
        ll sz = op2 - op1 + 1;
        ans += sy/sz*(pre[op2]-pre[op1-1]);
        ans += pre[op1+sy%sz-1] - pre[op1-1];
    }
    printf("%lld\n", ans);
    return 0;
}
