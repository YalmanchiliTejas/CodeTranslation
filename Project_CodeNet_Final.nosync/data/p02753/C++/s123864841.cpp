#include<bits/stdc++.h>
using namespace std;
#define forr(i,a,n)	for(int i=a; i<n; i++)
#define loop(i,a,n)	for(int i=a; i>=n; i--)

int main() 
{	
	ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	
	string s;
	cin>>s;int flag=0,flag2=0;
	forr(i,0,s.size())
	{
		if(s[i]=='A')	flag=1;
		if(s[i]=='B')	flag2=1;
	}
	if(flag==1 and flag2==1)	cout<<"Yes";
	else cout<<"No";
	return 0;	
}