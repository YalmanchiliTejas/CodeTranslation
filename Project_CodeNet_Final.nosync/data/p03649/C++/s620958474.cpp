#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll n,a[50],x;

int main(){
    cin>>n;
    ll num=0,ans;
    rep(i,n){
        cin>>a[i];
        num+=a[i]/n;
    }
    ans=num;
    while(num){
        rep(i,n){
            x=a[i]/n;
            a[i]%=n;
            a[i]+=num-x;
        }
        num=0;
        rep(i,n)num+=a[i]/n;
        ans+=num;
    }
    cout<<ans<<endl;
}