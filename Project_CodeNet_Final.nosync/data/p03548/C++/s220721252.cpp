#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y,z;
	cin>>x>>y>>z;
	x=x-z;
	y=y+z;
	z=x/y;
	cout<<z;
	return 0;
}