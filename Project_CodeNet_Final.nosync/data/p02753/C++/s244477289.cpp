#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.flush();
	ll t=1;
	//cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll a=0,b=0;
		for(ll i=0;i<3;i++)
		{
			if(s[i]=='A')
			{
				a++;
				}
			if(s[i]=='B')
			{
				b++;
				}
			}
		if((a==2 && b==1) || (a==1 && b==2))
		{
			cout<<"Yes"<<endl;
			}
		else
		{
			cout<<"No"<<endl;
			}
	}
	
return 0;
}
