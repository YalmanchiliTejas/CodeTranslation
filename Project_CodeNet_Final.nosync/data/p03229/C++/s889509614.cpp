#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ll pat1 = 0, pat2 = 0;
    if(n%2){
        //pattern1
        rep(i,n/2) pat1 += 2*a[n-i-1];
        rep(i,n/2-1) pat1 -= 2*a[i];
        pat1 -= (a[n/2-1]+a[n/2]);

        //pattern2
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