#include<bits/stdc++.h>
using namespace std;
 
 
void doit()
{
int a,b;
cin >> a>>b;
if(a==b)
	cout<<"Yes";
	else	cout<< "No";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t=1;
	//cin >>t;
	
	while(t--)
		doit();
	
	return 0;
}