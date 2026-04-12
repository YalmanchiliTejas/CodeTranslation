#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;

	x-=z;
	int count=0;
	while(x-y-z>=0){
		x-=(y+z);
		count++;
	}

	cout<<count<<endl;
} 