#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#define mod 1000000007
#define inf 1000000000000000
#define int long long int
int function2(string &str,int initial,int final,int memo[][4][3],int k,int status)
{
	if(k<0)
	   return 0;
	if(initial>final)
	{
		if(k==0)
		   return 1;
		else
		   return 0;
	}
	if(memo[initial][k][status]!=-1)
	    return memo[initial][k][status];
	else
	{
		int j;
		if(initial==0)
		{
			int val=str[initial]-48;
			if(status==0)
			{
				int answer=0;
				for(j=1;j<=val;j++)
				{
					if(j<val)
					{
						answer+=function2(str,initial+1,final,memo,k-1,1);
					}
					else
					{
						answer+=function2(str,initial+1,final,memo,k-1,0);
					}
				}
				memo[initial][k][status]=answer;
				return answer;
			}
			else
		    {
				int answer=0;
				for(j=1;j<=9;j++)
				{
					answer+=function2(str,initial+1,final,memo,k-1,1);
				}
				memo[initial][k][status]=answer;
				return answer;
			}
		}
		else
		{
			int val=str[initial]-48;
			if(status==0)
			{
				if(val==0)
				{
					int answer=0;
					answer+=function2(str,initial+1,final,memo,k,0);
					memo[initial][k][status]=answer;
					return answer;
				}
				else
				{
					int answer=0;
					answer+=function2(str,initial+1,final,memo,k,1);
					for(j=1;j<val;j++)
					{
						answer+=function2(str,initial+1,final,memo,k-1,1);
					}
					answer+=function2(str,initial+1,final,memo,k-1,0);
					memo[initial][k][status]=answer;
					return answer;
				}
			}
			else
			{
				int answer=0;
				answer+=function2(str,initial+1,final,memo,k,1);
				for(j=1;j<=9;j++)
				{
					answer+=function2(str,initial+1,final,memo,k-1,1);
				}
				memo[initial][k][status]=answer;
				return answer;
			}
		}
	}
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     string str;
     cin>>str;
     int k;
     cin>>k;
     int answer=0;
     int n=str.size();
     int j;
     for(j=1;j<n;j++)
     {
		 int memo[j+1][4][3];
		 for(int p=0;p<=j;p++)
		 {
			 for(int q=0;q<4;q++)
			 {
				 for(int r=0;r<3;r++)
				 {
					 memo[p][q][r]=-1;
				 }
			 }
		 }
		 answer+=function2(str,0,j-1,memo,k,1);
	 }
	 int memo[n+1][4][3];
	 for(int p=0;p<=j;p++)
	 {
		 for(int q=0;q<4;q++)
		 {
			 for(int r=0;r<3;r++)
			 {
				 memo[p][q][r]=-1;
			 }
		 }
	 }
	 answer+=function2(str,0,n-1,memo,k,0);
	 cout<<answer<<endl;
}
