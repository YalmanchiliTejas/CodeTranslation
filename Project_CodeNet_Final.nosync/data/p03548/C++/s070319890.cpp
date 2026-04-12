#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,ans=0;
	cin>>x>>y>>z;
	x-=2*z;
	while(x>=y){
		x-=y+z;
		ans++;
	}
	cout<<ans<<endl;
  return(0);
}