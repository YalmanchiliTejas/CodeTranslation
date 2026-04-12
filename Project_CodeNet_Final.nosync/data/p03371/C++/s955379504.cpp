#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,x,y;	cin>>a>>b>>c>>x>>y;
	int twin=min(a+b, c*2);
	long long ans=0;

	while(min(x,y)>0){
		ans+=twin;
		x--;
		y--;
	}
	
	if(x>0){
		ans += min(a*x, c*2*x);
	}else if(y>0){
		ans += min(b*y, c*2*y);
	}

	cout<<ans<<endl;

	return 0;
}
