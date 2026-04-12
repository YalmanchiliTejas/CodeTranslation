#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	int ans=(x-z)/(z+y);
	cout<<ans<<endl;
	return 0;
}