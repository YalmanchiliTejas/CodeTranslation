#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	if(a>=c*2){
		while(x>0){
			ans+=c*2;
			x--,y--;
		}
	}
	if(b>=c*2){
		while(y>0){
			ans+=c*2;
			x--,y--;
		}
	}
	if(a+b>=c*2){
		while(x>0 and y>0){
			ans+=c*2;
			x--,y--;
		}
	}
	while(x>0)ans+=a,x--;
	while(y>0)ans+=b,y--;
	cout<<ans<<endl;
}
