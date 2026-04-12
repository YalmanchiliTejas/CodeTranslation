#include<bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef long double ld;
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
#define debug(x) cerr<<#x<<" = "<<x<<endl

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

void solve()
{
    li n,x,M;

    cin>>n>>x>>M;

    if(x==1)
    {
        cout<<n;
        return;
    }

    if(x==0)
    {
        cout<<0;
        return ;
    }

    vi v(2e5);

    li ans=0;

    while(n>0)
    {
        ans+=x;

        x*=x;

        if(x>=M)
        {
            n--;
            break;
        }   
        n--;
    }

    if(n<=0)
    {
        cout<<ans;
        return ;
    }

    vi freq(2e5,-1);

    li pos=0;

    while(n>0)  
    {
        n--;
        x%=M;

        if(freq[x]==-1)
        {
            ans+=x;
            debug(ans);
            freq[x]=pos++;
            v[pos-1]=x;
        }
        else
        {
            n++;
            break;
        }

        x*=x;
        // n--;
    }

    if(n<=0)
    {
        cout<<ans;
        return;
    }

    debug(ans);

    li sz=pos;
    pos=freq[x];

    
    li sum=0,deno=0;

    f(i,pos,sz-1)
    {
        sum+=v[i];
        deno++;
    }

    li tp=n/deno;
    li rem=n%deno;

    ans+=tp*(sum);

    f(i,pos,pos+rem-1)
    {
        ans+=v[i];
    }

    // ans+=pre[rem-1];

    cout<<ans;
}

int main()
{    
    //remove this in kickstart

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    li t=1;

    // cin>>t;

    f(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";

        solve();
    }

    return 0;
}
