#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
		
		long long int x,y,z,ans;
		cin>>x>>y>>z;
		x-=z;
		ans=x/(y+z);
		cout<<ans<<"\n";
		return 0;
}