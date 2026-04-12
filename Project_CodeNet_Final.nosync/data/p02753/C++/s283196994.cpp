#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e9+7;

int main()
{
	string s;
	ll i, len, a=0, b=0;
	cin>>s;
	len=s.size();

	for(i=0;i<len; i++)
	{
		if(s[i]=='A')a++;
		else b++;
	}
	if(a==0||b==0)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}