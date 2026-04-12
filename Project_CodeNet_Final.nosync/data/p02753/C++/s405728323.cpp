#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);   
	ll n,a[200009],m,k,ans=0,fl=0;
	string s;
	cin>>s;
	for(int i=0;i<3;i++)
	{
		if(s[i]!=s[0])
			ans=1;
	}
	if(ans==1)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}