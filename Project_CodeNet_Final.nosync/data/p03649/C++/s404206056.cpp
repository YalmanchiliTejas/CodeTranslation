#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

int n;
int a[51];

bool f(int m){
    int cnt = 0;
    rep(i, 0, n){
        int tmp = (a[i] + m + 1) / (n + 1);
        cnt += tmp;
    }
    // cout << cnt << endl;
    return cnt <= m;
}

signed main(){
    cin >> n;
    bool g = true;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] >= n) g = false;
    }
    if(g){
        cout << 0 << endl;
        return 0;
    }
    int ng = 0, ok = 5 * 1e17;

    rep(i, 0, 100){
        int mid = (ng + ok) / 2;
        // int mid = i;
        if(f(mid)){
            ok = mid; //o("ok " << mid);
        }else{
            ng = mid; //o("ng " << mid);
        }
    }
    int ans = ok;
    rep(i, max((int)1, ok - 1000000), ok){
        if(f(i)){
            ans = i; break;
        }
    }
    cout << ans << endl;
}

