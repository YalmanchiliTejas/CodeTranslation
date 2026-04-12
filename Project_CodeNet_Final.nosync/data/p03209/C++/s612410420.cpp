#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ll total=(ll)pow(2,n+2)-3;
    //cout<<total;
    for (ll i = n; i >= 0; --i) {
        if(k>=(total+1)/2){
            ans+=(ll)pow(2,i);
            k-=(total+1)/2;
        }
        else{
            k-=1;
        }
        total=(total-3)/2;
    }
    cout<<ans<<endl;
}