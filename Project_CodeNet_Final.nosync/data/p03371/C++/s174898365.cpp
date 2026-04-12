#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int a,b,c,x,y;
    ll cost=0;
    cin>>a>>b>>c>>x>>y;
    ll ans=INFINITY;
    rep(i,100001){
        cost=2*c*i+a*max(0,x-i)+b*max(0,y-i);
        ans=min(ans,cost);
    }
    cout<<ans;
}