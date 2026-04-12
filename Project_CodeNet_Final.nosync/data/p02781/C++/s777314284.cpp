#include "bits/stdc++.h"
using namespace std;

const int N=1e2+20,MOD=1e9+7;

int k,len;
string a,b;
long long ans;

void go(int i,int k)
{
	if(k<0) return;
	if(i==len)
	{
		if(b<=a and k==0) ans++;
		return;
	}

	for(char c='0';c<='9';c++)
	{
		b[i]=c;
		if(k==0)
		{
			if(c=='0') go(i+1,k-(c!='0'));
		}
		else go(i+1,k-(c!='0'));
	}
}

int main()
{
	cin>>a>>k;

	len=a.size();
	for(int i=1;i<=len-1;i++)
	{
		if(i==1)
		{
			if(k==1) ans+=9;
		}
		else if(i==2)
		{
			if(k==1) ans+=9;
			else if(k==2) ans+=9*9;
		}
		else if(i==3)
		{
			if(k==1) ans+=9;
			else if(k==2) ans+=2*9*9;
			else ans+=9*9*9;
		}
		else
		{
			if(k==1) ans+=9;
			else if(k==2) ans+=9*(i-1)*9;
			else ans+=9*9*9*(i-1)*(i-2)/2;
		}
		ans%=MOD;
	}

	for(int i=1;i<=a[0]-'0'-1;i++)
	{
		if(k==1) ans++;
		else if(k==2) ans+=9*(len-1);
		else ans+=9*9*(len-1)*(len-2)/2;
		ans%=MOD;
	}

	b=a;
	if(k==1) ans++;
	else go(1,k-1);

	cout<<ans<<endl;
}