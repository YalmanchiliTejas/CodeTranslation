#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	int xx=x;
	int res=0;
	while(true){
		x-=y+z;
		if(x>0){
			res++;
		}
		else break;
	}
	
	if(((y * res) + (z * res))+z <= xx){
		cout<<res;
	}
	else{
		cout<<res-1;
	}
	return 0;
}