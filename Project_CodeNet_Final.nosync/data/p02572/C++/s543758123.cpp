#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < (n);i++)
#define lint long long
const lint mod=1e9+7;
const lint inf=2.19e15+1;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}

signed main(){
    int n;
    lint sum = 0;
    cin >> n;
    vector<lint>a(n);
    REP(i, n) cin >> a[i];
    vector<lint>acm(n+1);
    acm[0] = 0;
    REP(i, n){
        acm[i + 1] = (acm[i] + a[i]) % mod;
    }
    REP(i, n) {
        sum += acm[i] * a[i] % mod;
        sum %= mod;
    }
    cout << sum << endl;
}
