#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll x,y,z;
	cin>>x>>y>>z;
	x-=z;
	int t=y+z;
	cout<<x/t;
}