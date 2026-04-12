#include<bits/stdc++.h>
 
using namespace std;
 
#define lli long long
typedef long double ldb;
#define deci(n) fixed << setprecision(n)
 
lli M=1e9+7;
lli MOD=1e9+7;
 
#define MAXN 2000006 
 
// Template function //
lli powermod(lli x, lli y)  
{  
    lli res = 1;  
    x = x % MOD;
    if (x == 0) return 0;  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % MOD;  
        y = y>>1;   
        x = (x*x) % MOD;  
    }  
    return res;  
}
lli modinv(lli x)
{
    return powermod(x,MOD-2);
}
// Template functions end //
 
// Custom funtions //
lli findset(lli p[], lli x){
	if(x!=p[x]){
		p[x]=findset(p,p[x]);
	}
	return p[x];
}
 
void unionset(lli p[],lli r[],lli a,lli b){
	lli x=findset(p,a);
	lli y=findset(p,b);
	if(x!=y){
		if(r[x]<r[y]) swap(x,y);
		p[y]=x;
		if(r[x]==r[y]){
			r[x]++;
		}
	}
}

void dfs(vector<lli> v[], lli s[], lli x)
{
    lli S=1;
    for(lli i=0;i<v[x].size();i++)
    {
        dfs(v,s,v[x][i]);
        S+=s[v[x][i]];
    }
    s[x]=S;
}

lli f[100005];



void preprocess()
{
    f[0]=1;
    for(lli i=1;i<100005;i++)
    {
        f[i] = (f[i-1]*i)%MOD;
        if(i%2==0)
        f[i]/=2;
    }
}

lli tree[MAXN];


void buildTree(vector<lli> a, lli n)
{
    for(lli i=0;i<n;i++)
        tree[n+i] = a[i];
    for(lli i=n-1;i>0;i--)
    {
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}

void updateTree(lli n, lli p, lli value)
{
    tree[p+n] = value;
    p+=n;
    for(lli i=p; i>1;i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];
}

lli queryTree(lli n, lli l, lli r)
{
    lli res = 0;
    for(l+=n,r+=n;l<r;l>>=1, r>>=1)
    {
        if(l&1)
            res += tree[l++];
        if(r&1)
            res += tree[--r];
    }
    return res;
}

bool sortbysec(const pair<pair<lli,lli>,lli> &a, 
              const pair<pair<lli,lli>,lli> &b) 
{ 
    if(a.first.second == b.first.second)
    return a.first.first>b.first.first;
    return (a.first.second < b.first.second); 
} 

void dfs(int x, int vi[], vector<int> v[], long double pr, long double &ans)
{
    vi[x] = 1;
    double d = 0;
    for(int i=0;i<v[x].size();i++) 
    {
        if(vi[v[x][i]]==0)
        d++;
    }
    if(d==0)
    return;
    ans+=pr;
    pr = pr/d;
    for(int i=0;i<v[x].size();i++) 
    {
        if(vi[v[x][i]]==0)
        {
            dfs(v[x][i],vi,v,pr,ans);
        }
    }
}

void solve()
{ 
    int n;
    cin>>n;
    lli x;
    lli sum = 0;
    lli ans = 0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ans = (ans+(x*sum)%M)%M;
        sum = (sum+x)%M;
    }
    cout<<ans<<endl;
}
// Custom functions end //
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q=1;
    //cin>>q;
    for(lli tc=1;tc<=q;tc++)
    {
        solve();
    }
    return 0;
}