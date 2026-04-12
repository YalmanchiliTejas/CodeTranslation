#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define int long long int
#define read(a) int a; cin >> a;
#define readb(a, b) int a, b; cin >> a >> b;
#define readc(a, b, c) int a, b, c; cin >> a >> b >> c;
#define readarr(a, n) int a[(n) + 1] = {0}; FOR(i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define print(a) cout << a << endl;
#define printarr(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printv(v) for (int i: v) cout << i << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define vvi vector <vi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll MOD = 1e9+7;
const ll inf = 1e18;
const ll p = 998244353;
int fac[200005];
double powe(double x,int y) 
{ 
    if (y == 0) 
        return 1.00;
    double p = powe(x, y/2);
    p = (p * p); 
    return (y%2 == 0)? p : (x * p); 
} 
int power(int x,int y, int m) 
{ 
    if (y == 0) 
        return 1;
    int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
int mod(int x)
 {
	if(x<0)return -x;
	else return x;
 }
 int inverse(int a, int p)
{
    return power(a, p-2, p);
}
int ncr(int n, int r, int p)
{
    if (r==0)
        return 1;
    return (fac[n]*inverse(fac[r], p) % p *
            inverse(fac[n-r], p) % p) % p;
}
 int leaves=0;
 vector<int> visited;
 vector<set<int> > adj;
 vector<int> color;
 void dfs(int s)
{    
     
     if(visited[s])return;
     visited[s]=1;
     for(set<int>::iterator i=adj[s].begin();i!=adj[s].end();i++)
     {
     	if(!visited[*i])
     	{
     	 dfs(*i);	
		}
	 }
 }
 //Don't forget to clear vectors>>;
 //i miss simpu:3)(;
signed main()
{
read(n);
readarr(a,n);
int ans[n+2][n+2];
FOR(i,0,n+1)
{
	FOR(j,0,n+1)
	ans[i][j]=0;
}
FORD(i,n,1)
{
	FOR(j,i,n)
	{
		if((j-i)%2==(n-1)%2)
		{
			ans[i][j]=max(a[i]+ans[i+1][j],a[j]+ans[i][j-1]);
		}
		else
		ans[i][j]=min(ans[i+1][j]-a[i],ans[i][j-1]-a[j]);
	}
}
cout<<ans[1][n]<<endl;
}