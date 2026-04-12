#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	x-=z;
	cout<<(int)(x/(y+z))<<endl;
}