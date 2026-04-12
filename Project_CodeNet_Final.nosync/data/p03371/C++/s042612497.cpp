#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if(a+b>c*2){
		if(x==y)cout<<c*2*x<<endl;
		else if(x<y)cout<<c*2*x+min(b,c*2)*(y-x)<<endl;
		else cout<<c*2*y+min(a,c*2)*(x-y)<<endl;
	}
	else{
		cout<<a*x+b*y<<endl;
	}
}