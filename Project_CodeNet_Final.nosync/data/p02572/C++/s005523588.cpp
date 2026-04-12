#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arra[n+5];
    ll ans=0;
    for(int i=0;i<n;i++) {
        cin>>arra[i];
    }
    ll sum=0;
    for(int i=n-1;i>=0;i--) {
        ans+=(sum*arra[i]);
        sum+=arra[i];
    ans%=MOD;
    sum%=MOD;


    }
    cout<<ans<<endl;

}
