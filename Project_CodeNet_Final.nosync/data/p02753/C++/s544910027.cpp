#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;

int main()
{
	//#ifdef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	std::ios_base::sync_with_stdio(false);

	string s;
	cin>>s;
	ll a=0,b=0;
	f(3)
	{
	if(s[i]=='A')
		a++;
	if(s[i]=='B')
		b++;
}
	if(a>0 && b>0)
	{
		cout<<"Yes";
	}
	else
		cout<<"No";
	return 0;
}