#include<bits/stdc++.h> 
//#include<atcoder/all>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
//using namespace atcoder;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    ll ans2 = 0;
    int p = 0;
    int q;
    rep(i, (n - 2) / 2){
        ans -= a[i] * 2;
        ans2 += a[n - 1 - i] * 2;
        p++;
    }
    q = p;
    rep(i, n % 2 + 1){
        ans -= a[q + i];
        ans2 += a[n - 1 - q - i];
        p++;
    }
    q = p;
    rep(i, (n + 1) % 2){
        ans += a[q + i];
        ans2 -= a[n - 1 - q - i];
        p++;
    }
    q = p;
    rep(i, (n - 1) / 2){
        ans += a[q + i] * 2;
        ans2 -= a[n - 1 - q - i] * 2;
    }
    cout << max(ans, ans2) << endl;
}