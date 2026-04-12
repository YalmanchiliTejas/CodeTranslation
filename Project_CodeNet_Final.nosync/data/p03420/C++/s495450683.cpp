#include <iostream>
using namespace std;
typedef long long ll;
ll a,b,ans;
int main(void){
    cin>>a>>b;
    ll cnt=1;
    for(ll i=b+1;i<=a;i++){
        ans+=a/i*cnt;
        ans+=max(0LL,a%i-(b-1));
        cnt++;
        //cout<<ans<<endl;
    }
    if(b==0)cout<<a*a<<endl;
    else cout<<ans<<endl;
}
