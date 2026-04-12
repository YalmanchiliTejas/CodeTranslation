#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll p = 1e9 + 7;
#define DEBUG(x) cout << (x) << '\n'
#define fi first
#define se second

ll n, x, ans, last, pre[MAXN];
void run(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        pre[i-1] = (pre[i-1] + last) % p;
        ans = (ans + pre[i-1] * x % p) % p;
        pre[i] = pre[i-1], last = x;
    }
    DEBUG(ans);
}
int main(){
#ifdef Irene
    freopen("in.txt", "r", stdin);
#endif // Irene
    ios_base::sync_with_stdio(false);

    run(); return 0;
}
