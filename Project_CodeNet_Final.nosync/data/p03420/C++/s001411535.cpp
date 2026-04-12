#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll a,b;cin>>a>>b;
    ll ans=0;
    rep(i,b+1,a+1){
        ans+=(a/i)*(i-b)+max((ll)0,(a%i-b+1));
    }
    if(b==0)ans=a*a;
    cout<<ans<<endl;
}





