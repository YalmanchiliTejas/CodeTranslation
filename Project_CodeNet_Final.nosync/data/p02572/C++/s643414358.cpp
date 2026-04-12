#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin>>a[i];
        if(i==0) b[i]=a[i];
        else b[i]=b[i-1]+a[i];
    }
    ll ans=0;
    rep(i,n){
        ans+=a[i]*((b[n-1]-b[i])%NUM)%NUM;
    }
    ans%=NUM;
    cout<<ans;
}