#include<bits/stdc++.h>
using namespace std;
int r,g,b;
int main()
{
	cin>>r>>g>>b;
	if ((r*100+g*10+b)%4==0) cout<<"YES";
	else cout<<"NO";
	return 0;
 } 