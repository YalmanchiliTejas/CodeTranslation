#include<iostream>

using namespace std;

#define IOS ios::sync_with_stdio(0);cin.tie(0);

int main(){
	IOS;
	int x,y,z;
	while(cin>>x>>y>>z){
		x=x-2*z;
		int ans;
		ans=x/(y+z);
		if(x % (y+z) == y){
			ans+=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}