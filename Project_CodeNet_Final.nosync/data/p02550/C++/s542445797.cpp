#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main(){
	ll n,x,m;
	cin>>n>>x>>m;
	ll sum=0,temp=x,rep_sum,extra,i=0,len;
	unordered_map<ll,ll> ma,ma2;
	ma[x]=0;ma2[x]=1;i++;
	while(true){
		i++;
		sum+=temp;
		temp=(temp%m*temp%m)%m;
		if(ma.count(temp)){
			rep_sum=sum-ma[temp];
			extra=ma[temp];
			len=i-ma2[temp];
			break;
		}
		else ma[temp]=sum,ma2[temp]=i;
	}
	ll ans=extra+rep_sum*((n-ma2[temp]+1)/len);
	ll t=temp;
	for(int j=0;j<((ll)(n%len-ma2[t]%len+1%len+len)%len);j++){
		ans+=temp;
		temp=(temp%m*temp%m)%m;
	}
	cout<<ans<<endl;
}