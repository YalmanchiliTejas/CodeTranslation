#include <iostream>

using namespace std;

int main(){
	int x,y,z;
	int ans=0;
	cin>>x>>y>>z;
	for(int i=x;;){
		i-=y+z;
		//cout<<i<<endl;
		if(i<z)break;
		else if(i==z){
			ans++;
			break;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}