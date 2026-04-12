#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
#include<map>

typedef long long ll;

using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    ll i,j;
    ll a,b,c;
    ll x,y;
    cin>>a>>b>>c>>x>>y;
    ll ma=max(x,y);
    ll ans=2*ma*c;
    ll sa=0;
    ll big=0;
    if(x>y){
        sa=x-y;
        big=a;
    }else{
        sa=y-x;
        big=b;
    }
    ll ans1=0;
    ll temp1=0;
    for(i=0;i<=sa;i++){
        temp1=ans-2*i*c+i*big;
        if(ans>temp1){
            ans1=temp1;
        }
    }
    ll ans2=0;
    for(j=0;j<=min(x,y);j++){
        ll temp=temp1-2*j*c+j*(a+b);
        if(temp<ans){
            ans2=temp;
        }
    }
    if(ans1==0 && ans2!=0){
        cout<<ans2<<endl;
        return 0;
    }else if(ans2==0 && ans1!=0){
        cout<<ans1<<endl;
        return 0;
    }
    if(ans>ans1 && ans2>ans1){
        ans=ans1;
    }else if(ans>ans2 && ans1>ans2){
        ans=ans2;
    }else{
        ;
    }
    cout<<ans<<endl;
}

