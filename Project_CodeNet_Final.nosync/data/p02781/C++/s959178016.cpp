#include <bits/stdc++.h>
using namespace std;

long long com(long long n, int k)
{
	if (n<k)
	{
		return 0LL;
	}
	if (k==1)
	{
		return n;
	}
	else if (k==2)
	{
		return n*(n-1LL)/2LL;
	}
	else if (k==3)
	{
		return n*(n-1LL)*(n-2LL)/6LL;
	}
}

int main(int argc, char const *argv[])
{
	string n;
	int k;
	cin>>n>>k;
	long long ans=0LL;
	if (k==1)
	{
		ans+=(long long)9*(n.size()-1);
		ans+=(long long)n[0]-'0';
	}
	else if (k==2)
	{
		ans+=(long long)9*9*com(n.size()-1,k);
		ans+=(long long)(n[0]-'0'-1)*9*(n.size()-1);
		for (int i = 1; i < n.size(); ++i)
		{
			if (n[i]!='0')
			{
				ans+=(long long)9*(n.size()-i-1);
				ans+=(long long)n[i]-'0';
				break;
			}
		}
	}
	else if (k==3)
	{
		ans+=(long long)9*9*9*com(n.size()-1,k);
		ans+=(long long)(n[0]-'0'-1)*9*9*com(n.size()-1,2);
		for (int i = 1; i < n.size(); ++i)
		{
			if (n[i]!='0')
			{
				ans+=(long long)9*9*com(n.size()-i-1,2);
				ans+=(long long)(n[i]-'0'-1)*9*(n.size()-i-1);
				for (int j = i+1; j < n.size(); ++j)
				{
					if (n[j]!='0')
					{
						ans+=(long long)9*(n.size()-j-1);
						ans+=(long long)n[j]-'0';
						break;
					}
				}
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
