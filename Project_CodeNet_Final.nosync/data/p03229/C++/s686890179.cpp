#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
const int INF = 1e9;
using namespace std;

signed main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ll pat1 = 0, pat2 = 0;
    if(n%2){
        rep(i,n/2) pat1 += 2*a[n-i-1];
        rep(i,n/2-1) pat1 -= 2*a[i];
        pat1 -= (a[n/2-1]+a[n/2]);

        rep(i,n/2-1) pat2 += 2*a[n-i-1];
        rep(i,n/2) pat2 -= 2*a[i];
        pat2 += (a[n/2] + a[n/2+1]);
    }else{
        rep(i,n/2-1) pat1 += 2*a[n-i-1];
        pat1 += a[n/2];
        rep(i,n/2-1) pat1 -= 2*a[i];
        pat1 -= a[n/2-1];
        pat2 = pat1;
    }
    cout << max(pat1, pat2) << endl;
}
