#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;

	int count = 0;
	x-=z;
	while(x>=y+z){
		x-=z;
		x-=y;
		count++;
	}
	cout<<count;
}