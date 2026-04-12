#include <iostream>
using namespace std;
int a,b,c,x,y,ans,m,n;
int main(){
	cin>>a>>b>>c>>x>>y;
	if(a+b>2*c){
		if(x>=y){
			m=y*c*2+(x-y)*a;
			n=x*c*2;
			if(m>n) ans=n;
			else ans=m;
		}
		else{
			m=x*c*2+(y-x)*b;
			n=y*c*2;
			if(m>n) ans=n;
			else ans=m;
		}
	}
	else ans=x*a+y*b;
	cout<<ans;
	return 0;
}