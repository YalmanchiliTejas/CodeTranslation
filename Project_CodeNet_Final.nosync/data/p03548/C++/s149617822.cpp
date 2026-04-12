#include<iostream>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	
	x-=z;
	int cnt=0;
	while(x-z-y>=0){
		x-=z+y;
		cnt++;
	}
	
	cout<<cnt<<endl;
	return 0;
}