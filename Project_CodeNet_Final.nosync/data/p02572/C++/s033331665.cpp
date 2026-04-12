#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
int n;
ll ans,a[200005],s[200005],sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)  
     {
     	cin>>a[i];
     	s[i]=s[i-1]+a[i];
     }
    for(int i=1;i<=n;i++)
    {
    	sum=(sum+(s[n]-s[i])%MOD*a[i]%MOD)%MOD;
    }
    cout<<sum;
	return 0;
}
