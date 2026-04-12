#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
int n;
ll ans,a[200005],sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)  
     {
     	cin>>a[i];
     	ans=ans+a[i];
        ans=ans%MOD;
     }
    for(int i=1;i<=n;i++)
    {
    	ans-=a[i];
        if(ans<0) ans+=MOD;
        sum+=ans*a[i]%MOD;
        sum=sum%MOD;
    }
    cout<<sum;
	return 0;
}
