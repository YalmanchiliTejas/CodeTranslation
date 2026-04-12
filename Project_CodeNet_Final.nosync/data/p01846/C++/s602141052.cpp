#include<iostream>
using namespace std;
int m[9][9];
int w,h;
string s;
main()
{
	while(cin>>s,s!="#")
	{
		h=w=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='/')w=!++h;
			else
			{
				if(s[i]=='b')m[h][w++]=1;
				else
				{
					for(int j=0;j<s[i]-'0';j++)m[h][w++]=0;
				}
			}
		}
		w--;
		int a,b,c,d;cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		m[a][b]=0,m[c][d]=1;
		for(int i=0;i<=h;i++)
		{
			for(int j=0;j<=w;)
			{
				if(m[i][j++])cout<<'b';
				else
				{
					int cnt=0;
					j--;
					while(j<=w&&!m[i][j])cnt++,j++;
					cout<<cnt;
				}
			}
			if(i!=h)cout<<'/';
		}
		cout<<endl;
	}
}

