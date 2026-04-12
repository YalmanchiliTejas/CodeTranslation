#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;

	int ans,m=min(x,y),ma=max(x,y);
	if(c*2<a+b){
		ans=m*2*c+(x-m)*a+(y-m)*b;
	}else{
		ans=a*x+b*y;
	}

	if(ans>ma*c*2)
		ans=ma*c*2;

	cout<<ans<<endl;



}
