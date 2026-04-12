#include<iostream>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	int x,y,z;
	while(cin>>x>>y>>z){
		int ans=0;
		while(x){
			x-=z;
			if(x<=0) break;
			if(x<z) break;
			x-=y;
			if(x<=0) break;
			if(x<z) break;
			ans++;
		}
		cout<<ans<<endl;
	}
}
