#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,A[100000],sco,ans;
set<ll> se;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    for(ll c=1;c<n;c++){
        se.clear();
        sco=0;
        for(ll x=1;;x++){
            if(c*x>=n)break;
            se.insert(c*x);
            if(se.size()!=2*x-1)break;
            se.insert(n-1-c*x);
            if(se.size()!=2*x)break;
            sco+=A[c*x];
            a=n-1-c*x;
            sco+=A[a];
            //cout<<sco<<a<<c<<endl;
            if(a>c)ans=max(ans,sco);
        }
    }
    cout<<ans<<endl;
}
