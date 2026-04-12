#include<iostream>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) 
\

int main()
{
	string s;
	cin>>s;
	int ca=0,cb=0;
	REP(i,0,2)
	{
		if(s[i]=='A')
			ca++;
		else
			cb++;
	}
	if(ca==3 || cb==3)
		cout<<"No";
	else
		cout<<"Yes";
	
	return 0;
}