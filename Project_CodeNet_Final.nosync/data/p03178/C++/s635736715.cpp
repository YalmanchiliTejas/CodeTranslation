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
	// a better implementation Thanks to Errichto
	ios;
	string s;
	int n;
	cin>>s>>n;
	int len = s.size();
	vector<vector<int>> dp(n,vector<int> (2));

	// dp states are
	// sum,<a boolean value which shows whether I have already taken some digit smaller than the corresponding to the digit in k or not>

	dp[0][0]=1; // base case this means that total number of ways taking the imaginary digit at position -1 which is equal to its corresponding digit in s;

	for(int i=0;i<len;i++)
	{
		vector<vector<int>> v(n,vector<int> (2));

		for(int sum=0;sum<n;sum++)
		{
			for(bool already : {true,false})
			{
				for(int dig = 0;dig<10;dig++)
				{
					if(dig>s[i]-48 and !already)
						break;
					add(v[(sum+dig)%n][already || dig<s[i]-48],dp[sum][already]);
				}
			}
		}
		dp = v;
	}

	int ans = (dp[0][0]+dp[0][1])%M;
	ans--;
	if(ans<0)
		ans+=M;
	cout<<ans<<endl;
}