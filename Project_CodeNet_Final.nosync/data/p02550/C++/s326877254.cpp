#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll modi(ll a,ll n,ll MOD){
	if(n==0)
		return 1;
	else{
	    if(n%2==0){	      
         	ll temp=modi(a,n/2,MOD);	              
		    return (temp*temp)%MOD;		
        }
        else{
              return(a*modi(a,n-1,MOD))%MOD;	
        }
    }
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
        
	ll n,m,x;
	cin>>n>>x>>m;
	map<ll,ll>vis;
	map<ll,ll>rvis;
	vis[x]=1;
	rvis[1]=x;
	ll ans=x;
	for(ll i=1;i<n;i++){
		ll tans=modi(rvis[i],2,m);
		if(vis[tans]!=0){
			ll num=(i-vis[tans]+1);
			ll rem=n-i;
			ll ttans=0;
			for(ll j=vis[tans];j<=i;j++){
				ttans+=rvis[j];
			}
			ll ttansm=0;
			for(ll j=vis[tans];j<=vis[tans]+rem%num-1;j++){
				ttansm+=rvis[j];
			}	
			ans+=(ttans*(rem/num))+ttansm;
			break;	
		}
		else{
			vis[tans]=i+1;
			rvis[i+1]=tans;
			ans+=tans;
		}
	}
	cout<<ans<<endl;



	return 0;
}