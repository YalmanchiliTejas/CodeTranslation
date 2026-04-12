#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define x first
#define y second
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define MOD 1000000007
#define rc(x) return cout << x, 0

using namespace std;

ll n, a[55];
ll cnt, rs;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (1){
        sort(a+1, a+n+1, [&](ll a, ll b){return a > b;});
        if (a[1] < n) return cout << rs, 0;
        cnt = a[1] / n;
        rs += cnt;
        a[1] %= n;
        for (int i = 2; i <= n; i++) a[i] += cnt;
    }
}
