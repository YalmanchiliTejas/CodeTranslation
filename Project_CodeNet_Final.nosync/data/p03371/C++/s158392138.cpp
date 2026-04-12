#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(a+b<=2*c) cout<<x*a+y*b<<endl;
    else{
        ll ans=min(x,y)*2*c;
        if(x<=y){
            if(b<=2*c) ans+=b*(y-x);
            else ans+=2*c*(y-x);
        }else{
            if(a<=2*c) ans+=a*(x-y);
            else ans+=2*c*(x-y);
        }
        cout<<ans<<endl;
    }
    return 0;
}