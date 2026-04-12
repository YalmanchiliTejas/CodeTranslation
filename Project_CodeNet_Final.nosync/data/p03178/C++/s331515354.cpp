//Code by 27.
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>  
#include<memory.h> 
#include<sstream>
#include<time.h>
#include<iomanip>
using namespace std;
const unsigned long long BIGEST=1000000000000000000+1000000000000000000;
const long long BIGER=1000000000000000000;
const int BIG=1000000000;
const int MOD=1000000007;
const long long LMOD=1000000007;
string st;
int d;
long long f[10001][101][2];
int main()
{
	memset(f,0,sizeof(f));
	cin>>st>>d;
	f[0][0][1]=1;
	/*
	for(int i=0;i<=st.size();i++)
	{
		for(int j=0;j<=d;j++)
		{
			cout<<f[i][j][0]<<"-"<<f[i][j][1]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=0;i<st.size();i++)
	{
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<10;k++)
			{
				//if(i==1)cout<<"!";
				//if(j-k>=0)
				f[i+1][j][0]+=f[i][(j-k+d*10)%d][0];
				if(k<st[i]-'0')f[i+1][j][0]+=f[i][(j-k+d*10)%d][1];
				f[i+1][j][0]%=LMOD;
			}
		}
		for(int j=0;j<d;j++)
			{
				//if(j-st[i]+'0'>=0)
				f[i+1][j][1]+=f[i][(j-st[i]+'0'+d*10)%d][1];
				f[i+1][j][1]%=LMOD;
			}
	}
	/*
	for(int i=0;i<=st.size();i++)
	{
		for(int j=0;j<=d;j++)
		{
			cout<<f[i][j][0]<<"-"<<f[i][j][1]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<(f[st.size()][0][0]+f[st.size()][0][1]+LMOD-1)%LMOD;
	return 0;
}