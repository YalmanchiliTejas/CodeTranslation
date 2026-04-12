#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if(x>y){
        swap(x,y);
        swap(a,b);
    }
    ll ans=0;
    if(a+b>=2*c){
        ans+=2*c*x;
    }else{
        ans+=(a+b)*x;
    }
    //cout<<ans<<endl;
    if(b>=2*c){
        ans+=2*c*(y-x);
    }else{
        ans+=b*(y-x);
    }
    cout<<ans<<endl;
}