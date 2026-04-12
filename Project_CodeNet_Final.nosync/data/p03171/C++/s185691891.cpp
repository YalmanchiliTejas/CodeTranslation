#include <bits/stdc++.h>
#define ll long long
#define MAXN 200
using namespace std;
vector <vector <int> > adj;
vector <bool> visited;
vector <int> parent;
ll tree[MAXN];
ll bin[MAXN];
int fbs(int arr[], int l, int r, int x){
    int res = 0;
    while (l <= r){
        int m = l + (r-l)/2;
        if (arr[m] == x){
            res = m;
            r = m-1;
        }
        else if (arr[m] < x)
            l = m + 1;
        else
             r = m - 1;
        res = l;
    }
    return res;
}
int lbs(int arr[], int l, int r, int x){
    int res = 0;
    while (l <= r){
        int m = l + (r-l)/2;
        if (arr[m] == x){
            res = m;
            l = m+1;
        }
        else if (arr[m] < x)
            l = m + 1;
        else
             r = m - 1;
        res = l;
    }
    return res;
}
void dfs(int s)
{
    visited[s] = true;
    for(int i = 0; i<adj[s].size(); i++)
    {
        if(!visited[adj[s][i]])
        {
            parent[adj[s][i]] = s;
            dfs(adj[s][i]);
        }
    }
}
int bfs(int s)
{
    if(visited[s])
        return 0;
    queue <int> q;
    int ans = 0;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for(int i = 0; i<adj[s].size(); i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]] = true;
                q.push(adj[s][i]);
            }
        }
    }
    return ans;
}
void sieve(int n, vector <int> &primes)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
       {
           primes.push_back(p);
       }
}
int phi(int n)
{
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
void fin(int n , vector <int> &divs)
{
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                divs.push_back(i);
            else
            {
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
    }
}
int ct(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans += (x&1);
        x >>= 1;
    }
    return ans;
}
void build(int sti, int lo, int hi)
{
    if(lo == hi)
    {
        tree[sti] = 0;
        bin[sti] = 0;
        return ;
    }
    int left = 2*sti, right = 2*sti+1, mid = (lo+hi)/2;
    build(left, lo, mid);
    build(right, mid+1, hi);
    bin[sti] = bin[left] + bin[right];
    return;
}
void update(int sti, int sl, int sr, int in, int type)
{
    if(sl == sr && sl == in)
    {
        if(type == 1)
        {
            tree[sti] = 2*tree[sti] + 1;
            bin[sti] = ct(tree[sti]);

        }
        else
        {
            tree[sti] /= 2;
            bin[sti] = ct(tree[sti]);
        }
        return ;
    }
    int left = 2*sti, right = 2*sti+1, mid = (sl+sr)/2;
    if(in <= mid)
    {
        update(left, sl, mid, in, type);
    }
    else
    {
        update(right, mid+1, sr, in, type);
    }
    bin[sti] = bin[left] + bin[right];
}
int query(int sti, int sl, int sr, int lo, int hi)
{
    if(sl == lo && sr == hi)
    {
        return bin[sti];
    }
    int mid = (sl+sr)/2;
    int left = 2*sti, right = 2*sti + 1;
    if(hi<=mid)
    {
        return query(left, sl, mid, lo, hi);
    }
    else if(lo>mid)
    {
        return query(right, mid+1, sr, lo, hi);
    }
    else
    {
        return query(left, sl, mid, lo, mid)
             + query(right, mid+1, sr, mid+1, hi);
    }
}
const int N = 3005;
ll dp[N][N];
ll maxll(ll a, ll b)
{
	if(a>b)
		return a;
	return b;
}
ll solve(int i, int j, ll a[], int n)
{
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if(i==j)
	{
		dp[i][j] = a[i];
		return dp[i][j];
	}
	dp[i][j] = max(a[i] - solve(i+1, j, a, n), a[j] - solve(i, j-1, a, n));
	return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
			dp[i][j] = -1;
        }
    }
    int n;
    cin>>n;
    ll a[n];
    for(int i = 0; i<n; i++)
    {
    	cin>>a[i];
    }
    cout<<solve(0, n-1, a, n)<<endl;
    return 0;
}
