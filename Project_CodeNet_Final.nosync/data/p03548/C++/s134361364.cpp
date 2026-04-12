#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	x-=z;
	y+=z;
	x/=y;
	cout<<x;
	return 0;
}