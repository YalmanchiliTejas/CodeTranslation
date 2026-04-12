#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll a[n];
    REP(i,n){
        cin >> a[i];
    }
    sort(a, a + n);
    ll b[n];
    b[n / 2] = a[0];
    int now = 0;
    int t;
    for(int i = n / 2; i < n; i += 2){
        b[i] = a[now];
        now += 2;
        t = i;
    }
    int u = n - 1;
    if(t == n - 1) u = n - 2;
    for(int i = u; i > n / 2; i -= 2){
        b[i] = a[now];
        now += 2;
    }
    now = 1;
    for(int i = n / 2 - 2; i >= 0; i -= 2){
        b[i] = a[now];
        now += 2;
        t = i;
    }
    u = 0;
    if(t == 0) u = 1;
    for(int i = u; i < n / 2; i += 2){
        b[i] = a[now];
        now += 2;
    }
    ll ans1 = 0;
    REP(i,n - 1){
        ans1 += abs(b[i + 1] - b[i]);
    }
    reverse(a, a + n);
    b[n / 2] = a[0];
    now = 0;
    t;
    for(int i = n / 2; i < n; i += 2){
        b[i] = a[now];
        now += 2;
        t = i;
    }
    u = n - 1;
    if(t == n - 1) u = n - 2;
    for(int i = u; i > n / 2; i -= 2){
        b[i] = a[now];
        now += 2;
    }
    now = 1;
    for(int i = n / 2 - 2; i >= 0; i -= 2){
        b[i] = a[now];
        now += 2;
        t = i;
    }
    u = 0;
    if(t == 0) u = 1;
    for(int i = u; i < n / 2; i += 2){
        b[i] = a[now];
        now += 2;
    }
    ll ans2 = 0;
    REP(i,n - 1){
        ans2 += abs(b[i + 1] - b[i]);
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}