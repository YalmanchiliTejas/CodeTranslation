#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1e5+5;


int main()
{
	string s;
	cin>>s;
	int toa=0,tob=0;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A') toa++;
		if(s[i]=='B') tob++;
	}
	if(toa>0&&tob>0) cout<<"Yes\n";
	else cout<<"No\n";
	return 0; 
}