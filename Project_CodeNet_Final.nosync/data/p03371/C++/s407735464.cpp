#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int u=max(x,y);
	int ans=1145141919;
	for(int i=0;i<=u;i++){
		ans=min(ans,(2*c*i+a*max(x-i,0)+b*max(y-i,0)));
	}
	cout<<ans<<endl;
}