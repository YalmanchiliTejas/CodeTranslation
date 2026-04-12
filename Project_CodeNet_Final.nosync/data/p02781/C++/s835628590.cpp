#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int ln,k;
ll fun(int id,int ch,int k)
{
	ll ans=0;
	int vl=s[id]-'0';
	if(k==0) return 1;
	if(k<0 || id>=ln) return 0;
	if(ch && !vl) ans=fun(id+1,1,k);
	else ans=fun(id+1,0,k);
	for(int i=1;i<=9;i++)
	{
		if(ch)
		{
			if(i<vl) ans+=fun(id+1,0,k-1);
			else if(i==vl) ans+=fun(id+1,1,k-1);
		}
		else ans+=fun(id+1,0,k-1);
	}
	return ans;
}
int main()
{
	cin>>s>>k;
	ln=s.length();
	cout<<fun(0,1,k);
	return 0;
}