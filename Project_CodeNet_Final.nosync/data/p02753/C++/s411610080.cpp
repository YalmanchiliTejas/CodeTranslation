#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/*------------------------------------------------------------------*/

#define ll long long int
#define mp make_pair
#define pb push_back
#define MOD 1000000007

bool isvowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        return false;
}
ll isprime(ll n)
{
    ll ans=1;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            ans = i;
    }
    return ans;
}
ll power(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%m;
    ll temp=power(a,b/2,m);
    if(b%2==0)
        return ((temp%m)*(temp%m))%m;
    else
        return ((((temp%m)*(temp%m))%m)*a%m)%m;
}

/*-----------------------------------------------------------------------------*/

ll c(ll n, ll k)
{
    ll C[n + 1][k + 1];
    ll i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {

            if (j == 0 || j == i)
                C[i][j] = 1;

            else
                C[i][j] = (C[i - 1][j - 1]%MOD +
                          C[i - 1][j])%MOD;
        }
    }
    return C[n][k]%MOD;
}
ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {

        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;


        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;

    return x;
}
ll func(ll n)
{
    ll ans=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i/10==0)
                ans+=1+func(i)*func(n/i);
            else
                ans+=func(i)*func(n/i);
        }
    }
    return ans;
}
ll dp[2001][2001];
ll check(vector<pair<ll,ll> >v,ll l,ll r,ll i)
{ 
   //cout<<l<<" "<<r<<endl;
   if(l>r)
    return 0; 
   if(dp[l][r]!=-1)
    return dp[l][r]; 
   ll ans=0;
   ll p1=v[i].first;
   ll p2=v[i].second;
   ans=max(p1*(p2-l)+check(v,l+1,r,i+1),p1*(r-p2)+check(v,l,r-1,i+1));
   return dp[l][r]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    //freopen("1.txt","rt",stdin);
    //freopen("output.txt","wwt",stdout);

    ll t;
    t=1;
    //cin>>t;
    //ll t1=0;
    while(t--)
    {
      string s;
      cin>>s;
      if(s[0]==s[1]&&s[1]==s[2])
       cout<<"No";
      else
       cout<<"Yes"; 
    }
}
