
// Problem : E - Sequence Sum
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define pb push_back
#define mod 1000000007
ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
} 
ll factorial[1000007];
void fact(ll n)
{
    memset(factorial,0,sizeof(factorial));
    factorial[0]=1;
factorial[1]=1;

    for(int i=1;i<n;i++)
    {
        factorial[i]=(factorial[i-1]*i)%mod;
    }
    
}
ll ncr(ll n,ll r)
{
    ll ans=1;
    ll i;
    ans=factorial[n];
    ll ans1=power(factorial[n-r],mod-2);
    ll ans2=power(factorial[r],mod-2);
    ans=((ans*ans1)%mod*ans2)%mod;
    return ans;
}
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

bool prime[100000006];
void sieve(ll n){
    memset(prime,true,sizeof(prime));
	prime[1]=false; 
    for (ll p=2;p*p<=n;p++){
        if (prime[p]){  
            for (ll i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
}
void bfs(vector<int> v[],int o,int n,int dp[]){
	queue<int> q;
	q.push(o);
	dp[o]=0;
	bool visited[n+1]={0};
	visited[o]=true;
	while(q.empty()==false){
		int a=q.front();
		q.pop();
		for(int i=0;i<v[a].size();i++){
			if(visited[v[a][i]]==false){
				visited[v[a][i]]=true;
				q.push(v[a][i]);
				dp[v[a][i]]=dp[a]+1;
			}
		}
	}
}
int nov[1000001];
bool visited[1000001];
int dp[1000001];
int dfs(vector<int> v[],int o)
{
    if(visited[o]==0)
    {
        visited[o]=1;
        for(int i=0;i<v[o].size();i++)
        {
            if(visited[v[o][i]]==0)
            {
            dp[v[o][i]]=dp[o]+1;
            nov[o]+=dfs(v,v[o][i]);
            }
        }
        return nov[o]+1;
    }
    else
    return 0;
}
// string s=bitset<64>(n).to_string();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,m,x;
	cin>>n>>x>>m;
	// cout<<n<<x<<m<<endl;
	map<ll,ll> mp;
	vector<ll> v;
	ll temp=x;
	ll sum=0;
	while(mp.find(temp%m)==mp.end())
	{
		temp=temp%m;
		mp[temp]=v.size();
		v.pb(temp);
		// cout<<temp<<" ";
		temp*=temp;
	}
	ll idx=mp[temp%m];
	// cout<<idx<<endl;
	// cout<<endl;
	// cout<<v.size()<<endl;
	if(n<=idx)
	{
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=v[i];
		}
		cout<<sum<<endl;
	}
	else
	{
		ll sz=v.size()-idx;
		ll temp1=(n-idx)/sz;
		ll temp2=(n-idx)%sz;
		ll sum1=0;
		for(int i=idx;i<v.size();i++){
			sum1+=v[i];
		}
		ll res=sum1*temp1;
		for(int i=idx;i<idx+temp2;i++)
		{
			res+=v[i];
		}
		for(int i=0;i<idx;i++)
		{
			res+=v[i];
		}
		cout<<res<<endl;
	}
    
	return 0;
}
