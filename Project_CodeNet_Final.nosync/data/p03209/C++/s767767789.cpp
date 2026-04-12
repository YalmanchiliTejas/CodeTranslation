#include <bits/stdc++.h>
using namespace std;
using ll=int_fast64_t;
using P=pair<int,int>;
const ll INF=1<<30;
const ll LINF=1LL<<60;
const double EPS=1e-11;
int main(){
    ll n,x;cin>>n>>x;
    ll s[60],p[60];
    s[0]=1;
    p[0]=1;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]*2LL+3LL;
        p[i]=p[i-1]*2LL+1LL;
    }
    ll ans=0;
    if(x==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=n-1;i>=0;i--){
        if(x==s[i]+1){
            ans+=p[i];
            break;
        }else if(x==s[i]+2){
            ans+=p[i]+1;
            break;
        }else if(x>=s[i]*2+2){
            ans+=p[i]*2+1;
            break;
        }else if(x>s[i]+2){
            ans+=p[i]+1;
            x-=s[i]+2;
        }else{
            x--;
        }
    }
    if(x==1){

    }
    cout<<ans<<endl;
}