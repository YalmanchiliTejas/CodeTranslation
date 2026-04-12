#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n,k;
    ll ans=0;
    cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    for(int b=k+1;b<n+1;b++){
        ans+=n/b*(b-k);
        ans+=max((ll)0,n%b-k+1);
    }
    cout<<ans<<endl;
}