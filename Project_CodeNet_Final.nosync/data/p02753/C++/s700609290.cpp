#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	string x;
	cin>>x;
	int i,a=0,b=0;
	for(i=0;i<3;i++)
	{
		if(x[i]=='A') a++;
		else b++;
	}
	if(a*b!=0) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
	
}