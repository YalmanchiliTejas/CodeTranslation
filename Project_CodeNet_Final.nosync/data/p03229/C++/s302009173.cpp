#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    if(n%2==0){
        vector<ll> b(n);
        rep(i,n/2) b[2*i+1] = a[i];
        rep(i,n/2) b[2*i] = a[i+n/2];
        ll ans = 0;
        rep(i,n-1) ans += abs(b[i]-b[i+1]);
        cout << ans << endl;
    }else{
        vector<ll> b(n),c(n);
        rep(i,n/2){
            b[2*i+1] = a[i];
            c[2*i+1] = a[i+n/2+1];
        }
        rep(i,n/2+1){
            b[2*i] = a[i+n/2];
            c[2*i] = a[i];
        }
        swap(b[n-1],b[2]);
        swap(c[0],c[n-3]);
        ll res1 = 0,res2 = 0;
        rep(i,n-1){
            res1 += abs(b[i]-b[i+1]);
            res2 += abs(c[i]-c[i+1]);
        }
        cout << max(res1,res2) << endl;
    }
    return 0;
}

