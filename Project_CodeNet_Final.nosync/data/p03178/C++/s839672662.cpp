#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb(n) push_back(n)
const int N=55;
const ll M=1e9+7;
const ll inf=1e18;

void add(int& a,int b)
{
	a+=b;
	a%=M;
}

int main()
{



	ios;
	string s;
	int n;
	cin>>s>>n;
	int len = s.size();

	vector<vector<int>> dp(n,vector<int> (2));

	// the dp states are 
	// sum,flag  if(flag==1) 
	//				then we can put any digit 
	// 				at the current position
	// 			else the number is = k upto the current pos
	
	dp[0][0]=1; // indicates the formation of 0 but at POSITION -1
	for(int i=0;i<len;i++)
	{
		vector<vector<int>> temp(n,vector<int>(2));
		for(int sum = 0;sum<n;sum++)
		{
			// for strictly = k so far
			bool already = false;
			for(int dig = 0;dig<s[i]-48;dig++)
			{
				add(temp[(sum+dig)%n][1],dp[sum][0]);
			}
			add(temp[(sum+s[i]-48)%n][0],dp[sum][0]);

			already = true;

			for(int dig = 0;dig<10;dig++)
			{
				add(temp[(sum+dig)%n][1],dp[sum][1]);
			}
		}

		dp = temp;
	}

	int answer = (dp[0][0]+dp[0][1])%M;
	answer--;
	if(answer<0)
		answer+=M;
	cout<<answer<<endl;

}