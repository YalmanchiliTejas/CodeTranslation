#include<bits/stdc++.h>
#include<cstring>
using namespace std;
//#define num 1000000007
#define num 998244353
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define up(a,b) (((a)%(b)==0)?((a)/(b)):((a)/(b))+1)
#define inarr(i,a,n,A) for(ll i=a;i<n;i++) { cin>>A[i]; }
#define vll vector<long long>
#define pii pair <int,int>
#define pll pair<long long, long long>
#define vpii vector< pair <int,int>>
#define vpll vector< pair<long long, long long>>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) (a>b)?(a>c)?a:c:(b>c)?b:c
#define min3(a,b,c) (a<b)?(a<c)?a:c:(b<c)?b:c
#define avg(a,b) ((a)+(b))/2
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sf int flag=0     //Remember semicolon
#define assmin(a,b) if(b<=a) { a=b; }
#define assmax(a,b) if(b>=a) { a=b; }
#define fi first
#define s second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
typedef long long ll;
 
ll mymod(ll a, ll b)
{
	return (a%b + b)%b;
}
 
 
ll mod_exp(ll a, ll b, ll c)
{
	ll res=1;
	a=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%c;
		}
		b/=2;
		a=(a*a)%c;
	}
	return res;
}
ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}
bool prime[3001];
void SieveOfEratosthenes() 
{ 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;
    for (int p=2; p*p<=3000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=3000; i += p) 
                prime[i] = false; 
        } 
    } 
}
ll powe[20];
void power()
{
	powe[0]=1;
	REP(i,1,20)
	{
		powe[i]=(powe[i-1]*10)%num;
        if(powe[i]<0)
        powe[i]+=num;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,s;
	cin>>n>>s;
	ll A[n+1];
	REP(i,1,n+1)
	{
		cin>>A[i];
	}
	ll dp[n+1][s+1];
	ll dp2[s+1];
	REP(i,0,s+1) dp2[i]=0;
	REP(i,0,n+1) REP(j,0,s+1) dp[i][j]=0;
	REP(i,1,n+1)
	{
		if(A[i]<=s)
		{
		dp[i][A[i]]+=i;
		}
		REP(j,A[i]+1,s+1)
		{
				//cout<<dp[n][1]<<" cwjh\n";
				dp[i][j]+=dp2[j-A[i]];
				dp[i][j]=(dp[i][j]%num+num)%num;
		}
		REP(j,1,s+1)
		{
			dp2[j]+=dp[i][j];
			dp2[j]=(dp2[j]%num+num)%num;
		}
	}
	ll ans=0;
	REP(i,1,n+1)
	{
		ans+=dp[i][s]*(n-i+1);
		ans=mymod(ans,num);
	}
	cout<<ans<<"\n";
	return 0;
}