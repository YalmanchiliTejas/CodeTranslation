#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s;
	ll i,j,f=0;
	for(i=0;i<s.size()-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			f=1;break;
		}
	}
	if(f==1) cout<<"Yes";
	else cout<<"No";
}