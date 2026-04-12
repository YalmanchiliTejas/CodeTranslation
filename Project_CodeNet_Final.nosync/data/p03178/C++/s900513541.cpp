#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
ll sieve[1000001]={0},i,j;
ll m=1e9+7;
ll power(ll p, ll k)
{
ll a=1;
while(k)
{
if(k&1)
a=(a*p);
p=(p*p);
k>>=1;
}
return a;
}
using namespace std;
  ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
  
            else 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
void add_self(int &a ,int b)
{
	a+=b;
	if(a>=m)
	a-=m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int tc=1;
//cin>>tc;
ll cas=1;
 while(tc--)
 {
	string s;
	cin>>s;
	ll d;
	cin>>d;
	ll len=s.length();
	 vector<vector<int>> dp(d,vector<int>(2));
	dp[0][0]=1;
	for(ll where=0;where<len;where++)
	{
		vector<vector<int>> new_dp(d,vector<int>(2));
		for(ll sum=0;sum<d;sum++)
		{
			for(bool sm_already :{true,false})
			{
				for(ll digit=0;digit<10;digit++)
				{
					if(digit>s[where]-'0' && !sm_already)
					break;
					add_self(new_dp[(sum+digit)%d][sm_already || digit<s[where]-'0'],dp[sum][sm_already]);
				}
			}
		}
		dp=new_dp;
	}
	ll answer=(dp[0][false]+dp[0][true]-1+m)%m;
	cout<<answer;
	cout<<"\n"; 
 } 
}

