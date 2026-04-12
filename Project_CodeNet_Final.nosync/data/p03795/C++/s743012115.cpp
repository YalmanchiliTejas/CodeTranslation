#include <bits/stdc++.h>
using namespace std;
int main (){
	int n,x=0,y=0;
	cin>>n;
	x=n;
	while (x>=15){
		y=y+200;
	x=x-15;
	}
	cout<<(n*800-y);
	
	
	
}