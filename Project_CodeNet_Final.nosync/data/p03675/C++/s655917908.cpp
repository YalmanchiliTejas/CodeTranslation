#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            b[l++] = a[i];
        }else{
            b[r--] = a[i];
        }
    }
    // if(n % 2 == 0) reverse(b.begin(), b.end());
    for(int ii = 0; ii < b.size(); ii++){
        if(ii) cout << ' ';
        cout << b[ii];
    }
    cout << endl;
}