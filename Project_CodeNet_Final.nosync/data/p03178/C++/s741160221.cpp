#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7,mx=10005;
char s[mx];
int main()
{
  scanf("%s",s);
  int D;
  scanf("%d",&D);
  int len=strlen(s);
  vector<vector<int>>dp(D,vector<int>(2));
  dp[0][0]=1;
  for(int i=0;i<len;i++)
  {
  	   vector<vector<int>>new_dp(D,vector<int>(2));
	   for(int sum=0;sum<D;sum++)
	   {
		   	  for(int flag:{0,1})
		   	  {      int limit=flag?9:s[i]-'0' ;
				   	 for(int digit=0;digit<=limit;digit++)
				   	 {
				   	 int &ret= new_dp[(sum+digit)%D][flag||digit<limit];
				   	 ret+=dp[sum][flag];
				   	 if(ret>=mod)ret-=mod;
				   	 }
		   	  }  
	    }
	    dp=new_dp;
  }
  int answer=dp[0][0]+dp[0][1];
  cout<<(0LL+mod+answer-1)%mod;
  //cout<<answer;
}
