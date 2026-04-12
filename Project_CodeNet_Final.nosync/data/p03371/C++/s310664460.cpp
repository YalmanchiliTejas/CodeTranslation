#include<bits/stdc++.h>
using namespace std;
long long ans[5];
int main(){ 
	long long a,b,c,x,y,min_xy,max_xy;
	cin>>a>>b>>c>>x>>y;
	min_xy=min(x,y);
	max_xy=max(x,y);
	ans[0]=a*x+b*y;
	
	if(x>y){
		ans[1]=2*y*c+(x-y)*a;	
	} 
	else if(x<y){
		ans[1]=2*x*c+(y-x)*b;
	}
	else ans[1]=1000000000009;
	ans[2]=2*max_xy*c;
	sort(ans,ans+3);
	cout<<ans[0]<<endl;
	return 0;
}