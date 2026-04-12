#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
int main() {
    FIO;
    //test
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            ans+=(sum*a[i]);
            ans%=mod;
            sum+=a[i];
            sum%=mod;
        }
        cout<<ans<<endl;
    }
	return 0;
}
