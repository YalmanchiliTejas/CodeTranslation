#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=3e5+10;
int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int f=-1,f1=-1;
	for(auto it:s)
	{
		if(it=='B')
		{
			f=1;
		}
		if(it=='A')
			f1=1;
	}
	if(f==1&&f1==1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;






}
