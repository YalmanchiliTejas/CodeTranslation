#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll N;cin>>N;
    ll a[100010],ans=0;
    rep(i,0,N)cin>>a[i];
    sort(a,a+N);
    if(N%2==0){
    rep(i,0,N){
        if(i==N/2)ans+=a[i];
        else if(i>N/2)ans+=2*a[i];
        else if(i==N/2-1)ans-=a[i];
        else ans-=2*a[i];
    }
    }
    else{
        rep(i,0,N){
            if(i>N/2)ans+=2*a[i];
            else if(i==N/2)ans-=a[i];
            else if(i==N/2-1)ans-=a[i];
            else ans-=2*a[i];
        }
        ll MAX=ans;
        ans=0;
        sort(a,a+N,greater<>());
        rep(i,0,N){
            if(i>N/2)ans-=2*a[i];
            else if(i==N/2)ans+=a[i];
            else if(i==N/2-1)ans+=a[i];
            else ans+=2*a[i];
        }
        ans=max(MAX,ans);
    }
    cout<<ans<<endl;
}





