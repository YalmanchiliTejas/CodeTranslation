#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define     bit_1(a)       __builtin_popcount(a)
#define     ull            unsigned long long
#define     ll             long long
#define     pb             push_back
#define     pf             push_front
#define     mpr            make_pair
#define     ins            insert
#define     ff             first
#define     ss             second
#define     vi             vector<int>
#define     vl             vector<ll>
#define     vstr           vector<string>
#define     si             set<int>
#define     sl             set<ll>
#define     li             list<int>
#define     pii            pair<int,int>
#define     pll            pair<ll,ll>
#define     mii            map<int,int>
#define     mll            map<ll,ll>
#define     ma             INT_MAX
#define     mi             INT_MIN
#define     mod            1000000007
#define     pi             3.14159265359
#define     e              2.71828182846
#define     inf            1000000000000000LL
#define     all(x)         x.begin(), x.end()
#define     lb(a,b,c)      lower_bound(a,a+b,c)-a
#define     ub(a,b,c)      upper_bound(a,a+b,c)-a
#define     lbv(a,c)       lower_bound(all(a),c)-a.begin()
#define     ubv(a,c)       upper_bound(all(a),c)-a.begin()
#define     srt1(a,b)      sort(a,a+b)
#define     srt2(a,b)      sort(a,a+b,greater<int>())
#define     gcd(a,b)       __gcd(a,b)
#define     lcm(a,b)       (a*(b/gcd(a,b)))
#define     harmonic(n)    0.57721566490153286l+log(n)
#define     mem(a, b)      memset(a, b, sizeof(a))
#define     orderset1      tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define     orderset2      tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>

///s.lower_bound(a),s.upper_bound(a), for set
///nCr(x, y) = nCr(x-1, y-1) + nCr(x-1, y)
///factorial digit   ((n * log10(n / e) +log10(2 * pi * n) /2.0));
/// lcm(a,b)=a/gcd(a,b)*b (handle overflow)

bool sortinrev1(const pair<int,int>&a,const pair<int,int>&b)
{
    //return (a.first > b.first);
    if(a.first==b.first)
        return (a.second>b.second);
    else
        return (a.first > b.first);
}
bool sortinrev2(const pair<int,int>&a,const pair<int,int>&b)
{
    //return (a.first > b.first);
    if(a.first==b.first)
        return (a.second<b.second);
    else
        return (a.first > b.first);
}
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};

int parent[1000005];
//int ar[2000005];
bool mark[2000005];

int findParent(int node)
{
    if(parent[node]==node)
        return node;
    else
        return parent[node]=findParent(parent[node]);
}

void Union(int a,int b)
{
    int u=findParent(a);
    int v=findParent(b);
    if(u!=v)
        parent[u]=v;
}

int main()
{
    /*int d,t,s;
    cin>>d>>t>>s;
    if(t*s>=d)cout<<"Yes\n";
    else cout<<"No\n";*/
    /*string s,t;
    cin>>s>>t;
    int ans=10000000;
    for(int i=0;i<=s.size()-t.size();i++){
        int k=0,cnt=0;
        for(int j=i;j<i+t.size() && i+t.size()-1<s.size();j++){
            if(s[j]!=t[k])cnt++;
            k++;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;*/
    int n;
    cin>>n;
    ll ar[n+5];
    for(int i=1;i<=n;i++)cin>>ar[i];
    ll presum[n+5];
    mem(presum,0);
    for(int i=1;i<=n;i++)
        presum[i]=presum[i-1]+ar[i];
    ll sum=0;
    for(int i=1;i<n;i++){
        ll ans=(presum[n]-presum[i])%mod;
        ans=(ans*ar[i])%mod;
        sum=(sum+ans)%mod;
    }
    cout<<sum<<endl;
    /*int n,m,a,b,group=0;
    cin>>n>>m;
    mii mp;
    for(int i=1;i<=n;i++)parent[i]=i;
    while(m--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        Union(a,b);
        mp[a]=1;
        mp[b]=1;
    }
    vi v;
    for(int i=1;i<=n;i++){
        if(mp[i])
            v.pb(findParent(i));
    }
    mii cnt;
    sort(all(v));
    for(int i=0;i<v.size();i++)
        cnt[v[i]]++;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(cnt[i],ans);
    }
    cout<<ans<<endl;*/
    /*int n,cnt,maxx=0;
    cin>>n;
    mii mp;
    for(int i=0; i<n; i++){
        cin>>ar[i];
        mp[ar[i]]=1;
        maxx=max(maxx,ar[i]);
    }
    bool flag=false;
    for(int i=2; i<=maxx; i++){
        cnt=0;
        if(mp[i])cnt++;
        if(!mark[i]){
            mark[i]=true;
            for(int j=i+i; j<=maxx; j+=i){
                if(mp[j])cnt++;
                mark[j]=true;
            }
        }
        if(cnt>=2){
            flag=true;
            break;
        }
    }
    if(flag){
        int gcd=0;
        for(int i=0; i<n; i++)
            gcd=gcd(gcd,ar[i]);
        if(gcd==1)
            cout<<"setwise coprime\n";
        else
            cout<<"not coprime\n";
    }
    else
        cout<<"pairwise coprime\n";*/
}

