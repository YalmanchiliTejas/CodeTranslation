#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

int n, x;
int length[51], p[51];
int ans = 0;

void calc(int lv, int r){
    if(lv == 0){
        if(r == 0) ans++; 
        return;
    }
    if(r == length[lv] - 1){
        ans += p[lv]; return;
    }
    if(r == 0) return;
    if(r <= length[lv - 1]){
        calc(lv - 1, r - 1); return;
    }
    calc(lv - 1, length[lv - 1] - 1);
    ans++;
    calc(lv - 1, r - (length[lv - 1] + 1) - 1);
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    x--;
    length[0] = 1;
    p[0] = 1;
    rep(i, 1, 51){
        length[i] = length[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    calc(n, x);
    cout << ans << endl;
}