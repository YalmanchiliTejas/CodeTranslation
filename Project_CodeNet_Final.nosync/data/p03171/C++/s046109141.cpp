#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define ui unsigned ll
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0)
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define f first
#define INF pow(10,14)+7
#define s second
ll N=300000;
vector<bool>visited(N+1,false);
//bool visited[505][505];
// use ((x%n)+n)%n when x can be negative
bool isprime(ll x)
{
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(x%i ==0 ) return false;
    }
    return true;
}
void findfact (ll x,map<ll,vector<ll>>&m)
{
    for(ll i=3;i*i<=x;i+=2)
    {
        if(x%i==0)
        {
            if(i==x/i) m[x].push_back(i);
            else
            {
                 m[x].push_back(i);
                 m[x].push_back(x/i);
            }
            break;
        }
    }
    return;
}
struct cmp{
    bool operator() (const pair<ll,ll>& a, const pair<ll,ll>& b){
        if(a.f>b.f) return false;
        else if(a.f<b.f) return true;
        if(a.second<b.second) return false;
        return true; 
    }
};
bool isPalindrome(string t)
{
    ll st=0;
    ll end=t.size()-1;
    while(st<=end)
    {
        if(t[st]!=t[end]) return false;
        st++;
        end--;
    }
    return true;
}
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
bool pow2 (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
} 
/*void dfs(vector<vector<char>>&s,ll i,ll j,ll n,ll m,ll &t,ll k,ll count)
{
    if(i<0||j<0||i==n||j==m||visited[i][j]||s[i][j]=='#'||t>=count-k)
    return;
    visited[i][j]=true;
    s[i][j]='*';
    t++;
    if(i>=1) dfs(s,i-1,j,n,m,t,k,count);
    if(j>=1) dfs(s,i,j-1,n,m,t,k,count);
    if(i<n-1) dfs(s,i+1,j,n,m,t,k,count);
    if(j<m-1) dfs(s,i,j+1,n,m,t,k,count);
}*/
ull factorial(ull n) 
{ 
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
} 
ull binomialCoeff(ull  n, ull k)  
{  
    ull res = 1;  
  
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k )  
        k = n - k;  
  
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (ull i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
}
vector<ll>hp;
void primeFactors(ll  n)  
{  
    // Prll the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        hp.push_back(2);
        n = n/2;  
    }  
  
    // n must be odd at this poll. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, prll i and divide n  
        while (n % i == 0)  
        {  
            hp.pb(i);
            n = n/i;  
        }  
    }  
    if(n>2) hp.pb(n);
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
}  
ll minFlipsMonoIncr(string S) { //flips to make binary string increasing 
        ll flip=0;
        ll ones=0;
        bool flag=false;
        for(ll i=0;i<S.size();i++)
        {
            if(S[i]-'0'==1) flag=true;
            if(flag&&S[i]-'0'==0) flip++;
            else if(S[i]=='1') ones++;
            if(flip>ones) flip=ones;
        }
        return flip;
}
ll kadane(vector<ll>arr)
{
    ll curr=0;
    ll maxsum=INT_MIN;
    for(ll i=0;i<arr.size();i++)
    {
        curr+=arr[i];
        maxsum=max(maxsum,curr);
        curr=max(curr,(ll)0);
    }
    return maxsum;
}
ll func(vector<vector<ll>>&dp,vector<ll>&arr,ll start,ll end, bool flag)
{
    if(start==end) return dp[start][start]=arr[start];
    if(dp[start][end]!=-1) return dp[start][end];
        return dp[start][end]=max(arr[start]-func(dp,arr,start+1,end,!flag),arr[end]-func(dp,arr,start,end-1,!flag));
}
int main() {
    	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	    #endif
        IOS;
        ll T=1;
        //cin>>T;
        while(T--)
        { 
            ll n,k;
            cin>>n;
            vector<ll>arr(n);
            for(ll i=0;i<n;i++) 
            {
                cin>>arr[i];
            }
            bool flag=true;
            vector<vector<ll>>dp(n,vector<ll>(n,-1));
            func(dp,arr,0,arr.size()-1,flag);
            cout<<dp[0][n-1];
            //cout <<setprecision(9) << ans << '\n';

        }
        
        
}