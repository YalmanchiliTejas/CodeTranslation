#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=100000000000000000;

ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=0;
    if(a+b>2*c){
        if(x>y){
            ans+=y*c*2;
            if(a>c*2){
                ans+=c*2*(x-y);
            }else{
                ans+=a*(x-y);
            }
        }else{
            ans+=x*c*2;
            if(b>c*2){
                ans+=c*2*(y-x);
            }else{
                ans+=b*(y-x);
            }
        }
    }else{
        ans=x*a+y*b;
    }
    cout<<ans<<endl;
    
    return 0;
}

