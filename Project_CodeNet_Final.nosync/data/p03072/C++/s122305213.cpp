#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mx 200005
#define gcd __gcd
#define pb push_back
#define mk make_pair
#define bs binary_search
using namespace std;

bool isp[mx];

void sv(){

	ll i,j;
	memset(isp, true, sizeof(isp));
	
	isp[1]= false;
	for(i=2;i*i<mx;i++){
		if(isp[i]){
			for(j=i*i;j<mx;j+=i)
			isp[j]= false;
		}
	}
}

ll powr(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	//sv();
	ll n,a[mx],i,j;
    cin>>n;
    ll tmp=0,ans=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=tmp){
            ans++;
            tmp= a[i];
        }
    }
    cout<<ans;
    return 0;
}