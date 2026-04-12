/*********************
*  Author: xuziyuan  * 
*********************/
 
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
const LL MOD=1e9+7;

string s,ss;
int t,ans=0;
bool ok;

int main()
{
	cin>>s>>t;
	if(s.size()<t)
	{
		puts("0");
		return 0;
	}
	if(t==3&&s.size()-1>=3) ans=(s.size()-1)*(s.size()-2)*(s.size()-3)/6*9*9*9;
	else if(t==2&&s.size()-1>=2) ans=(s.size()-1)*(s.size()-2)/2*9*9;
	else if(t==1&&s.size()-1>=1) ans=(s.size()-1)*9;
	rep(i,s.size()) ss.pb('0');
	if(t==3)
	repn(i,9)
	{
		if(i>s[0]-'0') break;
		if(i<s[0]-'0') ans+=(s.size()-1)*(s.size()-2)/2*9*9;
		else
		repn(j,9)
		{
			repn(k,9)
			{
				repn(p,s.size()-1)
				{
					for(int r=p+1;r<s.size();r++)
					{
						rep(rr,s.size()) ss[rr]='0';
						ss[0]=i+'0';
						ss[p]=j+'0';
						ss[r]=k+'0';
						ok=true;
						rep(rr,s.size())
						{
							if(ss[rr]>s[rr])
							{
								ok=false;
								break;
							}
							if(ss[rr]<s[rr]) break;
						}
						if(ok) ans++;
					}
				}
			}
		}
	}
	else if(t==2)
	{
		repn(i,9)
		{
			if(i>s[0]-'0') break;
			if(i<s[0]-'0') ans+=(s.size()-1)*9;
			else
			repn(j,9)
			{
				repn(k,s.size()-1)
				{
					rep(p,ss.size()) ss[p]='0';
					ss[0]=i+'0';
					ss[k]=j+'0';
					ok=true;
					rep(rr,s.size())
					{
						if(ss[rr]>s[rr])
						{
							ok=false;
							break;
						}
						if(ss[rr]<s[rr]) break;
					}
					if(ok) ans++;
				}
			}
		}
	}
	else if(t==1) ans+=s[0]-'0';
	cout<<ans<<endl;
	return 0;
}