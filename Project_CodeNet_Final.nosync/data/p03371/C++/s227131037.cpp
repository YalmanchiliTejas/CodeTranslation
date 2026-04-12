#include<iostream>
using namespace std;

int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int ans=0;
	if(2*c>=a+b) ans+=(a+b)*min(x,y);
	else ans+=c*2*min(x,y);
	int r=max(x,y)-min(x,y);
	if(r>0){
		int big=(max(x,y)==x?a:b);
		if(2*c >= big) ans+=big*r;
		else ans+=2*c*r;
	}
	cout << ans << endl;
}
