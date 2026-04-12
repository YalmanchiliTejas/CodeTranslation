#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    ll ans=1LL<<60;
    rep(i,2*(x+y)+10){
        int j=max(0,(2*x-i+2-1)/2);
        int k=max(0,(2*y-i+2-1)/2);
        ll tmp=j*a+k*b+i*c;
        ans=min(ans,tmp);
    }

    cout<<ans<<endl;
}
