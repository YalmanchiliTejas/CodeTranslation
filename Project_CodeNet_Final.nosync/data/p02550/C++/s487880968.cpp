#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll f[m] = {};
    f[x] = 1;

    ll ans = 0;
    if(n <= 1000000){
        rep(i,n){
            ans += x;
            x = x * x % m;
        }
        cout << ans << endl;
        return 0;
    }

    ll xx = x;
    ll loop = 0;
    ll start = 0;
    while(true){
        ll nx = x * x % m;
        int now = f[x] + 1;
        if(f[nx] != 0){
            loop = now - f[nx];
            start = f[nx];
            break;
        }
        f[nx] = now;
        x = nx;
    }

    x = xx;
    rep(i,start-1){
        ans += x;
        x = x * x % m;
        n--;
    }

    ll sum = 0;
    rep(i,m) f[i] = 0;
    f[x] = 1;
    sum = x;
    rep(i,loop-1){
        ll nx = x * x % m;
        f[nx] = 1;
        x = nx;
        sum += x;
    }

    ans += (n/loop)*sum;
    n -= n/loop*loop;

    
    while(n>0){
        n--;
        x = x*x%m;
        ans += x;
    }

    cout << ans << endl;
    return 0;
}


