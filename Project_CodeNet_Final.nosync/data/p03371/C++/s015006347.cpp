#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int amore=max(0,x-y);
	int same=min(x,y);
	int bmore=max(0,y-x);
	int ans=0;
	ans=min(a,c*2)*amore+min(a+b,c*2)*same+min(b,c*2)*bmore;
	cout<<ans<<endl;
}
