#include <bits/stdc++.h>

using namespace std;

string s;
int K;
long long int ans;

long long int Comb(long long int n,long long int m)
{
	if(m>n)
	    return 0;
	if(m==n || m==0)
	    return 1;
	if(m==1)
	    return n;
	if(m==2)
	    return n*(n-1)/2;
}

int main()
{
	cin>>s;
	scanf("%d",&K);
	if(K==1)
	{
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<s.size();j++)
			    ans++;
			if(i<=s[0]-'0')
			    ans++;
		}
	}
	if(K==2)
	{
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				for(int k=2;k<s.size();k++)
					ans=ans+Comb(k-1,1);
				if(i<s[0]-'0')
					ans=ans+Comb(s.size()-1,1);
				else
				{
					if(i==s[0]-'0')
					{
						int loc=s.size();
						for(int k=1;k<s.size();k++)
						{
							if(s[k]!='0')
							{
								loc=k;
								break;
							}
						}
						if(loc<s.size())
						{
							ans=ans+s.size()-loc-1;	
						    if(j<=s[loc]-'0')
						        ans++;
						}		      
					}
				}
			}
		}
	}
	if(K==3)
	{
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				for(int k=1;k<=9;k++)
				{
					for(int l=3;l<s.size();l++)
					    ans=ans+Comb(l-1,2);
					if(i<s[0]-'0')
					    ans=ans+Comb(s.size()-1,2);
					else
					{
						if(i==s[0]-'0')
						{
							int loc=s.size()-1;
							for(int l=1;l<s.size()-1;l++)
							{
								if(s[l]!='0')
								{
									loc=l;
									break;
								}
							}
							if(loc<s.size()-1)
							{
								if(j<s[loc]-'0')
								{
									ans=ans+Comb(s.size()-loc-1,1);
							        if(loc<s.size()-2)
							            ans=ans+Comb(s.size()-loc-1,2);
								}
								else
								{
									if(j==s[loc]-'0')
									{
										if(loc<s.size()-2)
							                ans=ans+Comb(s.size()-loc-1,2);
										int loc1=s.size();
								    	for(int l=loc+1;l<s.size();l++)
									    {
									    	if(s[l]!='0')
										    {
											    loc1=l;
						    					break;
							    			}
								    	}
									    if(loc1<s.size())
									    {
										    ans=ans+(long long)(s.size()-1-loc1);
										    if(k<=s[loc1]-'0')
										        ans++;
									    }
									}
									if(j>s[loc]-'0' && loc<s.size()-1)
								        ans=ans+Comb(s.size()-1-loc,2);
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 