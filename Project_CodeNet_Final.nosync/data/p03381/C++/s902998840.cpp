#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    vector<int> b = a;
    sort(all(b));
    int l = b[n / 2 - 1];
    int r = b[n / 2];
    rep(i, 0, n){
        if(a[i] <= l){
            cout << r << endl;
        }else{
            cout << l << endl;
        }
    }
}