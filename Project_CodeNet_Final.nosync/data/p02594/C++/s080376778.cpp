#include <bits/stdc++.h>
#include <fstream>
#include<string.h>
#include <algorithm>
#include<math.h>
#include<vector>
#include <queue>
#include <deque> 
#define ll long long
#define M 1000000007 
#define MM 998244353
using namespace std;
 
ll prck(ll n)
{
    ll f=1;
    if(n==1)
        f=0;
    else if(n==2)
        f=1;
    else if(n%2==0)
        f=0;
    else
    {
        ll i;
        for(i=3;(i*i<=n) && (f==1);i+=2)
        {
            if(n%i==0)
                f=0;
        }
    }
    return f;
}
 
ll nCr(ll n,ll r)
{
    ll i,res = 1;
    if (r>n-r)
        r=n-r;
    for(i=0;i<r;++i)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
ll btod(string n)
{
    ll lg=n.length();
    ll i,val=0,bs=1;
    for(i=lg-1;i>=0;i--)
    {
        if(n[i]=='1')
        {
            val+=bs;
        }
        bs*=2;
    }
    return val;
}
 
ll ston(string s)
{
    ll val=0,bs=1;
    ll sl=s.length();
    sl--;
    while(sl>=0)
    {
        val+=((s[sl]-48)*bs);
        bs*=10;
        sl--;
    }
    return val;
}
 
 
ll nCrModpDP(ll n, ll r, ll p)
{
    ll i,j,C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (i=1;i<=n;i++)
    {
        for(j=min(i,r);j>0;j--)
        {
            C[j] = (C[j]+C[j-1])%p;
        }
    }
    return C[r];
}
ll nCrModpLucas(ll n,ll r,ll p)
{
   if (r==0)
      return 1;
   ll ni = n%p, ri = r%p;
   return (nCrModpLucas(n/p, r/p, p) *
           nCrModpDP(ni, ri, p)) % p;
}
 
//(x^y)%p
ll pwr(ll x,ll y,ll p)
{
    ll res=1;
    x = x % p;
    while(y>0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
//for bigger data
/*ll mul_mod(ll a, ll b, ll mod)
{
    ll res = 1;
    a=a%mod;
    while(b)
    {
        if(b & 1)
            res = ((__int128)res * a) % mod;
        a = ((__int128)a * a) % mod;
 
        b >>= 1;
    }
    return res;
}*/

 
ll modInverse(ll n,ll p)
{
    return pwr(n, p-2, p);
}
 
ll nCrModPFermat(ll n, ll r, ll p,ll fac[])
{
   if (r==0)
      return 1;
 
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
 
/*ll fac[n+1];
        fac[0] = 1;
        ll i;
        for (i=1 ; i<=n; i++)
            fac[i] = fac[i-1]*i%M;*/
 
/*ll nPr(ll n,ll r,ll m,ll fac[])
{
    ll q=fac[n];
    r=(fac[r])%m;
    return (q*pow(r,m-2))%m;
}*/
 
// ll power(int x, unsigned int y)
// {
//     int temp;
//     if( y == 0)
//         return 1;
//     temp = power(x, y/2);
//     if (y%2 == 0)
//         return temp*temp;
//     else
//         return x*temp*temp;
// }
 
//Zeller's Congruence
int calcDate(int date,int month,int year)
{
    if(month==1)
    {
        month=13;
        year--;
    }
    if(month==2)
    {
        month=14;
        year--;
    }
    int q=date,m=month,k=year%100,j=year/100;
    int day = q + (13*(m+1))/5 + k + (k/4) + (j/4) + 5*j;
    day=day%7;
    return day;
}
 
 
vector<vector<ll>> matmul(vector<vector<ll>> a,vector<vector<ll>> b)
{
    ll k=a.size();
    vector<vector<ll>> c(k,vector<ll>(k));
    ll i,j,l;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            for(l=0;l<k;l++)
            {
                c[i][j]=(c[i][j]+a[i][l]*b[l][j])%M; //%Mo only if req.
            }
        }
    }
    return c;
}
 
vector<vector<ll>> matexp(vector<vector<ll>> a,ll p)
{
    if(p==1)return a;
    if(p&1)return matmul(a,matexp(a,p-1));
    vector<vector<ll>> x= matexp(a,p/2);
    return matmul(x,x);
}
 
//linear recurrence
//find Fn
ll linrec(ll n,ll k,vector<ll> a,vector<ll> b)
{
    if(n==0)return 0;
    if(n<=k)return a[n-1];
    ll i,j;
    vector<ll> F1(k+1);
    for(i=1;i<=k;i++)F1[i]=a[i-1];
    vector<vector<ll>> T(k+1,vector<ll>(k+1));
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i<k)
            {
                if(j==i+1)
                    T[i][j]=1;
                else T[i][j]=0;
                continue;
            }
            T[i][j]=b[k-j];
        }
    }
 
    T=matexp(T,n-1);
    ll res=0;
    for(i=1;i<=k;i++)
    {
        res+=(T[1][i]*F1[i])%M;
    }
    return res%M;
}
 
/*primefactors[a]=primefactors[a/primediviser[a]]+1*/
/*
    ll N=5000000+200;
    ll p[N]={},d[N],i,j;
    for(i=2;i<N;i++)
    {
        if(p[i]!=0)continue;
        for(j=i;j<N;j+=i)
        {
            if(p[j]==0)p[j]=i;
        }
    }
    d[1] = 0;
    for(i=2;i<N;i++)d[i]=1+d[i/p[i]];
    for(i=2;i<N;i++)d[i]+=d[i-1];
*/
 
ll modexp(ll x, ll n)
{
    if (n == 0)return 1;
    else if (n % 2 == 0)
    {
        return modexp((x * x) % M, n / 2);
    }
    else
    {
        return (x * modexp((x * x) % M, (n - 1) / 2) % M);
    }
}
 
ll getFractionModulo(ll a, ll b)
{
    ll c = gcd(a, b);
    a = a / c;
    b = b / c;
    ll d = modexp(b, M - 2);
    ll ans = ((a % M) * (d % M)) % M;
    return ans;
}

ll INF=(1LL<<60)-1;
ll dfs(ll x,ll vis[],vector<ll> adj[],ll p[],ll h[],ll good[],ll bad[])
{
    vis[x]=1;
    for(ll child:adj[x])
    {
        if(vis[child]==0)
        {
            dfs(child,vis,adj,p,h,good,bad);
            good[x]+=good[child];
            bad[x]+=bad[child];
        }
    }
    ll reqg,reqb;
    reqg=(p[x]+h[x])/2;
    if((p[x]+h[x])%2 || reqg<0 || reqg>p[x])
    {
        //flg=1;
    }
    reqb=p[x]-reqg;
    if(reqg<good[x])
    {
        //flg=1;
    }
    bad[x]=reqb;
    good[x]=reqg;
}

void dfs2(ll x,ll par,ll val,vector<pair<ll,ll>> adj[],ll dist[],ll l[],ll r[])
{
    dist[x]=max(dist[x],val);
    ll sz=adj[x].size(),child,i;
    ll flg=0;
    for(i=0;i<sz;i++)
    {
        if(adj[x][i].first==par)
        {
            adj[x].erase(adj[x].begin()+i);
            flg=1;
            break;
        }
    }
    if(flg)sz--;
    for(i=0;i<sz;i++)
    {
        child=adj[x][i].first;

        if(i==0)l[child]=dist[child]+adj[x][i].second;
        else
        {
            l[child]=max(l[adj[x][i-1].first],dist[child]+adj[x][i].second);
        }
    
    }
    for(i=sz-1;i>=0;i--)
    {
        child=adj[x][i].first;

        if(i==sz-1)r[child]=dist[child]+adj[x][i].second;
        else
        {
            r[child]=max(r[adj[x][i+1].first],dist[child]+adj[x][i].second);
        }

    }
    ll mx;
    for(i=0;i<sz;i++)
    {
        child=adj[x][i].first;
        mx=val;
    
        if(i>0)mx=max(mx,l[adj[x][i-1].first]);
     
        if(i<sz-1)mx=max(mx,r[adj[x][i+1].first]);
  
        dfs2(child,x,mx+adj[x][i].second,adj,dist,l,r);
        
    }
}

void bfs2(ll node,ll par,vector<ll> adj[],ll n)
{
    queue<pair<ll,ll>> q;
    q.push({node,par});
    //cout<<node<<" -> "<<par<<"\n";
    ll vis2[n]={};
    vis2[node]=1;
    ll prev2[n];
    while(!q.empty())
    {
        pair<ll,ll> cur=q.front();
        q.pop();
        for(ll child:adj[cur.first])
        {
            if(child==cur.second)continue;
            prev2[child]=cur.first;
            q.push({child,cur.first});
            vis2[child]=1;
            if(child==par)break;
        }
        if(vis2[par]==1)break;
    }
}

void bfs(ll node,ll vis[],vector<ll> adj[],ll prev[],ll col[],ll n)
{
    queue<pair<ll,ll>> q;
    q.push({node,-1});
    ll ptr,cnt=0;
    while(!q.empty())
    {
        pair<ll,ll> cur=q.front();
        q.pop();
        vis[cur.first]=1;
        cnt++;
        for(ll child:adj[cur.first])
        {
            if(child==cur.second)continue;
            col[child]=1-col[cur.first];
            if(vis[child]==1)
            {
            
                bfs2(child,cur.first,adj,n);
                //cout<<child<<" "<<cur.first<<"\n";
                break;
            }
            else
            {
                q.push({child,cur.first});
                prev[child]=cur.first;
            }
        }
        
    }
}
 
void addSelf(ll &a,ll b)
{
    a+=b;
    while(a>=M)a-=M;
}
 
void subSelf(ll &a,ll b)
{
    a-=b;
    while(a<0)a+=M;
}
 
struct sr{
    ll type,val,ind;
};
 
bool cmp(struct sr aa,struct sr ab)
{
    if(aa.val==ab.val)return aa.type<ab.type;
    return aa.val>ab.val;
}

ll f[200002];
 
ll find(ll x)
{
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}
 
bool connected(ll a,ll b)
{
    a=find(a);
    b=find(b);
    if(a==b)return 1;
    f[a]=b;
    return 0;
}

struct segtree
{
    ll size;
    vector<pair<ll,ll>> sums;
    
    void init(ll n)
    {
        size=1;
        while(size<n)
        {
            size*=2;
        }
        sums.assign(2*size,{0LL,0});
    }
    void build(vector<ll> &a,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            if(lx < (ll)a.size())
            {
                sums[x]={a[lx],1};
            }
            return;
        }
        ll mid=(lx+rx)/2;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
        sums[x]=merge(sums[2*x+1],sums[2*x+2]);
    }
    
    void build(vector<ll> &a)
    {
        build(a,0,0,size);
    }
    
    pair<ll,ll> merge(pair<ll,ll> a,pair<ll,ll> b)
    {
        if(a.first<b.first)return a;
        else if(b.first<a.first)return b;
        return {a.first,a.second+b.second};
    }
    void set(ll i,ll v,ll x,ll lx, ll rx)
    {
        if(rx-lx==1)
        {
            sums[x]={v,1};
            return;
        }
        ll mid=(lx+rx)/2;
        if(i<mid)
        {
            set(i,v,2*x+1,lx,mid);
        }
        else
        {
            set(i,v,2*x+2,mid,rx);
        }
        sums[x]=merge(sums[2*x+1],sums[2*x+2]);
    }
    
    void set(ll i,ll v)
    {
        set(i,v,0,0,size);
    }
    
    pair<ll,ll> calc(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(lx>=r || rx<=l)
        {
            pair<ll,ll> res=make_pair(INF,0LL);
            return res;
        }
        if(lx>=l && rx<=r)return sums[x];
        ll mid=(lx+rx)/2;
        pair<ll,ll> s1=calc(l,r,2*x+1,lx,mid);
        pair<ll,ll> s2=calc(l,r,2*x+2,mid,rx);
        return merge(s1,s2);
    }
    
    pair<ll,ll> calc(ll l,ll r)
    {
        return calc(l,r,0,0,size);
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*ll t,w;
    cin>>t;
    w=0;
    while(w<t)
    {*/
        //cout<<"Case #"<<w+1<<": ";
        ll n;
        cin>>n;
        if(n>=30)cout<<"Yes\n";
        else cout<<"No\n";
        /*w++;
    }*/
    return 0;
}
