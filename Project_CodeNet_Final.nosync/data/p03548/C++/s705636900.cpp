//    >File Name: 2.cpp
//    > Author: Webwei

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z;
	cin >> x >> y >> z;
	int sum = 1;
	x-=z;
	sum=(x/(y+z));
	cout << sum << '\n';
	return 0;
}
