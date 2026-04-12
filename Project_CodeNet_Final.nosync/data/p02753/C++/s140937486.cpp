#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pob pop_back
#define vl vector<ll>
#define mp make_pair
#define sz size()
#define fast ios::sync_with_stdio(0)
#define maxx 100005
#define edge pair<ll,ll>
using namespace std;


int main()
{
	string s;
	cin>>s;
	ll i;
	ll flag=0;
	for(i=0;i<2;i++)
	{
		if(s[i]!=s[i+1])
		{
			flag++;
		}
	}
	if(flag>0)
	cout<<"Yes";
	else
	cout<<"No";
}