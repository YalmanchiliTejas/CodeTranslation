#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	long long a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	long long ans=a*x+b*y,d=min(x,y),e=max(x,y);
	if(ans>d*c*2+a*(x-d)+b*(y-d)){
		ans=d*c*2+a*(x-d)+b*(y-d);
	}
	if(ans>e*c*2){
		ans=e*c*2;
	}
	cout<<ans<<endl;
    return(0);
}