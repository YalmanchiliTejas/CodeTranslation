#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a,b,c,x,y,ans,ans0,ans1,ans2;
  	
  	cin>>a>>b>>c>>x>>y;
  	map<ll,ll> mp;
  	mp[x]=a;
  	mp[y]=b;
  	
		ans0=a*x+b*y;
		ans1=c*2*min(x,y)+mp[max(x,y)]*abs(x-y);
        ans2=c*2*max(x,y);
      	ans=min({ans0,ans1,ans2});
    	cout<<ans<<endl;
      return 0;
    
}	