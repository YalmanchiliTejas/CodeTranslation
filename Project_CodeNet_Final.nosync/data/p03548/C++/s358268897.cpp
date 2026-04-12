#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,ans=0;
	cin>>x>>y>>z;
	for(int i=1; ;i++){
		if(i*y+(i+1)*z<=x) ans++;
		else{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}