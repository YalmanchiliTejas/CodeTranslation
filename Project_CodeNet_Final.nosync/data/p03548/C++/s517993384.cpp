#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;
int main()
{
	int X,Y,Z,M;
	cin>>X>>Y>>Z;
	M = (X - Z)/(Y + Z);
	cout<<M<<endl;
	return 0;
}