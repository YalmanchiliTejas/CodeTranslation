#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<int,int> P;
typedef pair<int,P> PP;
string s[10];
int flag;
int zu[12][12];
int main()
{
	int w,h;
	cin>>w>>h;
	rep(i,w)
	{
		cin>>s[i];
		rep(j,h)
		{
			if(s[i][j]=='#')zu[i+1][j+1]=1;
		}
	}
	flag=1;
	rep2(i,1,w+1)rep2(j,1,h+1)
	{
		if(!((i==1&&j==1)||(i==w&&j==h)))
		{
			if(zu[i][j]==1)
			{
				if(!(zu[i-1][j]+zu[i][j-1]==1&&zu[i+1][j]+zu[i][j+1]==1))
				{
					flag=0;
				}
			}
		}
		else if(i==1&&j==1)
		{
			if(!(zu[i+1][j]+zu[i][j+1]==1))flag=0;
		}
		else
		{
			if(!(zu[i-1][j]+zu[i][j-1]==1))flag=0;
		}
	}
	if(flag)
	{
		cout<<"Possible"<<endl;
	}
	else cout<<"Impossible"<<endl;
	return 0;
}