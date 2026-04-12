#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<"="<<x<<endl;
#define endl '\n'
#define M 1000000007
#define int long long

using namespace std;

void solve()
{
	string s;
	cin>>s;
	ll a=0,b=0;

	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='A')a++;
		else b++;		/* code */
	}
	if(a>0 && b>0)cout<<"Yes";
	else cout<<"No";
}

int32_t main() 
{
	IOS	
	ll T=1;
	 // cin>>T;
	while(T--)
	{
    		solve();
	}
}