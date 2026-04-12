#include<bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef vector<li> vi;
typedef pair<li,li> pi;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define B begin()
#define E end()
#define f(i,l,r) for(li i=l;i<=r;++i)
#define fr(i,l,r) for(li i=l;i>=r;--i)
#define u_map unordered_map
#define endl "\n"

li fastpow(li base,li exp,li M) 
{
    li res=1;
    while(exp>0) {
        if(exp&1)
            res=(res*base)%M;

        base=(base*base)%M;
        exp>>=1;
    }
    return res;
}

vi par,sz,vis;
vector<vi> graph;

void init(li n)
{
    par.resize(n);
    sz.resize(n);
    vis.resize(n);
    graph.resize(n);

    f(i,0,n-1)
    {
        par[i]=i;
        sz[i]=1;
    }
}

li root(li a)
{
    while(a!=par[a])
    {
        par[a]=par[par[a]];
        a=par[a];
    }

    return a;
}

void unio(li a,li b)
{
    li r_a=root(a);
    li r_b=root(b);

    if(par[r_a]!=r_b)
    { 
        if(sz[r_a]<sz[r_b])
        {
            par[r_a]=par[r_b];
            sz[r_b]+=sz[r_a];
            sz[r_a]=0;
        }
        else
        {
            par[r_b]=par[r_a];
            sz[r_a]+=sz[r_b];
            sz[r_b]=0;
        }
    }
}

int main()
{    
 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    li n,m;

    cin>>n>>m;

    if(n==m)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}