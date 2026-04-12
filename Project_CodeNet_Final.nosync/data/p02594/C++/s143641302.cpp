#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

bool isInteger(double n)
{
	if(floor(n)==ceil(n))
		return true ;
	return false ;
}

using namespace std ;

int main()
{
	int x;
	cin>>x;
	if(x>=30)
		cout<<"Yes";
	else
		cout<<"No";
}
