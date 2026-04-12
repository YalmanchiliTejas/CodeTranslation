#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
	int r, g, b;
	cin>>r>>g>>b;
	r*=100;
	g*=10;
	int ans = r+g+b;
	if (ans%4==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
