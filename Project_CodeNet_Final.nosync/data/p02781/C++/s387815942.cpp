#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
	long long n,i,j,k,ans,y;
	ans=0;
	string x,xx;
	cin>>x;
	cin>>k;
	if (k==1)
	{
		ans=ans+(x.length()-1)*9+int(x[0])-48;
		cout<<ans<<endl;
	}
	else if (k==2)
	{
		i=x.length();
		if (i>=2)
		{
			ans=ans+((i-2)*(i-1)*81)/2;
			for (j=1;j<i;j++)
			{
				if (x[j]=='0')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			ans=ans+(int(x[0])-49)*(i-1)*9;
			if (j==i)
			{
				ans=ans;
			}
			else
			{
				ans=ans+(i-j-1)*9;
				ans=ans+int(x[j])-48;	
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	else
	{
		i=x.length();
		if (i>=3)
		{
			y=0;
			ans=ans+((i-1)*(i-2)*(i-3)*729)/6;
			//cout<<ans<<endl;
			ans=ans+((int(x[0])-49)*81*(i-2)*(i-1))/2;
			//cout<<ans<<endl;
			for (j=1;j<i;j++)
			{
				if (x[j]=='0')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			xx="";
			while (j<i)
			{
				xx=xx+x[j];
				j++;
			}
			//cout<<xx<<endl;
			i=xx.length();
			y=y+((i-2)*(i-1)*81)/2;
			for (j=1;j<i;j++)
			{
				if (xx[j]=='0')
				{
					continue;
				}
				else
				{
					break;
				}
			}
			y=y+(int(xx[0])-49)*(i-1)*9;
			if (j==i)
			{
				y=y;
			}
			else
			{
				y=y+(i-j-1)*9;
				y=y+int(xx[j])-48;	
			}
			ans=ans+y;
			cout<<ans<<endl;						
		}
		else
		{
			cout<<0<<endl;
		}		
	}
}