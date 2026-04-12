#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mod 998244353
#define f first
#define se second
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
typedef long long ll ;
typedef long double ld ;
typedef long long int lli;

using namespace std;
//reference: geeks
ll mult(ll a,ll b, ll p=mod){	return ((a%p)*(b%p))%p;	}
ll add(ll a, ll b, ll p=mod){ if(a>=p) a%=p; if(b>=p) b%=p; if(a+b>p) return (a + b)%p; else return a+b;}
ll sub(ll a, ll b, ll p=mod){return (a%p - b%p + p)%p;}
ll fpow(ll n, ll k, ll p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = mult(r,n,p); n = mult(n,n,p);} return r;}
ll inv(ll a, ll p = mod) {return fpow(a, p - 2, p);}
#define INF 10000000000
#define MAXL 1000005
ll spf[MAXL];
vector<ll>prime;
void seive()
{
    for(int i=2;i<MAXL;i++)
        spf[i]=i;
    for(ll i=2;i<MAXL;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=2*i;j<MAXL;j+=i)
                if(spf[j]==j)
                    spf[j]=i;
            prime.pb(i);
        }
    }
    //cout<<prime.size();
}
ll dp[3006][3006][2];
int main()
{
		ll n;
		cin>>n;
		ll a[n];
		for(int i=0;i<n;i++)	cin>>a[i];

		for(int i=0;i<n;i++)
		{
			dp[i][i][0]=a[i];
			dp[i][i][1]=-a[i];
		}
		for(int len=1;len<n;len++)
		{
			//cout<<"\n";
			for(int i=0;i<n-len;i++)
			{
				dp[i][i+len][0]=max(a[i]+dp[i+1][i+len][1],a[i+len]+dp[i][i+len-1][1]);
				//cout<<i<<" "<<i+len<<" "<<0<<" "<<dp[i][i+len][0]<<"\n";
				dp[i][i+len][1]=min(-a[i]+dp[i+1][i+len][0],-a[i+len]+dp[i][i+len-1][0]);
				//cout<<i<<" "<<i+len<<" "<<1<<" "<<dp[i][i+len][1]<<"\n";
			}
			//cout<<"\n";
		}
		/*cout<<"\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<dp[i][j][0]<<" ";
			}
			cout<<"\n";
		}

		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<dp[i][j][1]<<" ";
			}
			cout<<"\n";
		}*/
		cout<<dp[0][n-1][0];

}