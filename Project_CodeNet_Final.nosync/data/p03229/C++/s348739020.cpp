using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;

signed main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll s=0,s1=0,s2=0;
    if(n%2==0){
        rep(i,(n/2)-1){
            s += 2*a[n-1-i];
            s -= 2*a[i];
        }
        s += a[n/2];
        s -= a[(n/2)-1];
    }else{
        rep(i,(n-3)/2) s1 += 2*a[n-1-i];
        rep(i,(n-1)/2) s1 -= 2*a[i];
        s1 += a[(n+1)/2];
        s1 += a[(n-1)/2];
        rep(i,(n-1)/2) s2 += 2*a[n-1-i];
        rep(i,(n-3)/2) s2 -= 2*a[i];
        s2 -= a[(n-1)/2];
        s2 -= a[(n-3)/2];
        s = max(s1,s2);
    }
    cout<<s<<endl;
}
