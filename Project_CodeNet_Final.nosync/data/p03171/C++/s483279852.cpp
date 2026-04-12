#include<bits/stdc++.h>
#pragma GCC optimize ("-O3")
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define diff(a,b) (a>b?a-b:b-a)
#define F first
#define S second
const int N=1e6+5;
int mod = 1e9+7;
void pairsort(int a[], int b[], int n){
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) 
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    sort(pairt, pairt + n);
    for (int i = 0; i < n; i++) 
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
ll pow1(ll n,ll p)
{
    if(p==0)    return 1;
    ll x=pow1(n, p/2);
    x=(x*x)%mod;
    if(p%2==0)
        return x;
    else
        return (x*n)%mod;
}
ll binarySearch(ll arr[], ll l, ll r,ll x) 
{ 
    if (r >= l) 
    { 
        ll mid = l + (r - l) / 2;  
        if (arr[mid] == x) 
        return mid; 
        if (arr[mid] > x) 
        return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    }
    return -1; 
}
bool compare(const pair<ll, ll>&p1, const pair<ll,ll>&p2)
{
    if(p1.F < p2.F) return true;
        if(p1.F == p2.F) return p1.S < p2.S;
        return false;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
int isPrime(int n){
    if(n < 2)
        return 0;
    if(n < 4)
        return 1;
    if(n % 2 == 0 or n % 3 == 0)
        return 0;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 or n % (i+2) == 0)
            return 0;
    return 1;
}
long long C(int n, int r) {
    if(r>n-r) 
        r=n-r;
    long long ans=1;
    for(int i=1;i<=r;i++){
        ans*=n-r+i;
        ans/=i;
    }
    return ans;
}
int modexpo(int x,int p){
    int res = 1;
    x = x%mod;
    while(p){
        if(p%2)
            res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}

int n;
vector<int>a;
vector<vector<int>>dp;
int game(int start, int end){

	if(start>end)return 0;
    if(dp[start][end]!=-1)return dp[start][end];
	int ans = 0;

	ans = max(a[start]+min(game(start+2, end), game(start+1, end-1)), a[end]+min(game(start, end-2), game(start+1, end-1)));
	return dp[start][end] = ans;
}
int32_t main()
{
    IOS;
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    dp.resize(n+1, vector<int>(n+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)dp[i][j] = -1;
    }
    int ans1 = game(1, n);
    int ans2 = min(game(2,n), game(1,n-1));
	cout<<ans1-ans2<<endl;
    return 0;
}
