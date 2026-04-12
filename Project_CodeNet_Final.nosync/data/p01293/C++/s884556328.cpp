#include<iostream>
#include<algorithm>
using namespace std;
char t;
int f(char a)
{
	if(a>'0'&&a<='9')return a-'0';
	else
	{
		switch(a)
		{
			case'T':return 10;
			case'J':return 11;
			case'Q':return 12;
			case'K':return 13;
			case'A':return 14;
		}
	}
}
main()
{
	while(cin>>t,t!='#')
	{
		string s[4][13];
		for(int i=0;i<4;i++)for(int j=0;j<13;j++)cin>>s[i][j];
		int cnt[2]={};
		char u=t;
		for(int i=0;i<13;i++)
		{
			int mt=-1,mu=-1,mc=-1;
			char su;
			for(int j=0;j<4;j++)
			{
				if(s[j][i][1]==t)mt=max(mt,f(s[j][i][0]));
				else if(s[j][i][1]==u)mu=max(mu,f(s[j][i][0]));
				else mc=max(mc,f(s[j][i][0]));
			}
			if(mt>0)
			{
				for(int j=0;j<4;j++)if(s[j][i][1]==t&&f(s[j][i][0])==mt)
				{
					cnt[j%2]++;
					if(i<12)su=s[j][i+1][1];
				}
			}
			else if(mu>0)
			{
				for(int j=0;j<4;j++)if(s[j][i][1]==u&&f(s[j][i][0])==mu)
				{
					cnt[j%2]++;
					if(i<12)su=s[j][i+1][1];
				}
			}
			else
			{
				for(int j=0;j<4;j++)if(f(s[j][i][0])==mc)
				{
					cnt[j%2]++;
					if(i<12)su=s[j][i+1][1];
				}
			}
			u=su;
		}
		if(cnt[0]<cnt[1])cout<<"EW "<<cnt[1]-6<<endl;
		else cout<<"NS "<<cnt[0]-6<<endl;
	}
}

