#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll          long long
#define pb          push_back
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define rs(v,n)     v.resize(n)
#define hell        1000000007
#define peak        9123372036854775807
#define pii         acos(-1)
#define clr(a,x)    memset(a,x,sizeof(a))
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ordered_set tree<ll int, null_type,less<ll int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
template<class x,class y> x sum(x a,y b){return a+b;}
template<class x,class y> x mul(x a,y b){return a*b;}
template<class x,class y> x sub(x a,y b){return a-b;}
template<class x,class y> x divi(x a,y b){return a/b;}

template<class x,class y>
istream &operator>>(istream &in,pair<x,y> &p) 
{ 
    in>>p.F>>p.S;
    return in;
}
template<class x>
istream &operator>>(istream &in,vector<x> &v) 
{
    for(auto& i:v)
        in>>i;
    return in;
}
template<class x,class y>
ostream &operator<<(ostream &out,pair<x,y> &p) 
{ 
    out<<"("<<p.F<<","<<p.S<<") ";
    return out; 
}
template<class x>
ostream &operator<<(ostream &out,vector<x> &v) 
{ 
    out<<v.size()<<endl;
    for(auto i:v)
        out<<i<<" ";
    out<<endl;
    return out; 
}
#define N  100005
ll n,l,r;
vi a(N),seg(4*N);
void build(ll cur,ll st,ll end)
{
    if(st==end)
    {
        seg[cur]=a[st];
        return;
    }
    ll mid=(st+end)>>1;
    build(2*cur,st,mid);
    build(2*cur+1,mid+1,end);
    seg[cur]=max(seg[2*cur],seg[2*cur+1]);    /*  1-change here  */
}
ll query(ll cur,ll st,ll end,ll l,ll r)
{
    if(l<=st&&r>=end)
    return seg[cur];
    if(r<st||l>end)
    return -1;                           /*  2-change here  */
    ll mid=(st+end)>>1;
    ll ans1=query(2*cur,st,mid,l,r);
    ll ans2=query(2*cur+1,mid+1,end,l,r);
    return max(ans1,ans2);                 /*  3-change here  */
}
void update(ll cur,ll st,ll end,ll pos,ll upd)
{
    if(st==end)
    {
        a[pos]=upd;                    /*  4-change here  */
        seg[cur]=upd;                    /*  5-change here  */
        return;
    }
    ll mid=(st+end)>>1;
    if(st<=pos&&pos<=mid)
        update(2*cur,st,mid,pos,upd);
    else
        update(2*cur+1,mid+1,end,pos,upd);
    seg[cur]=max(seg[2*cur],seg[2*cur+1]);    /*  6-change here  */
}
int main()
{
    ios;
    ll tt=1;
    // cin>>tt;
    while(tt--)
    {
        ll i,j,k,l,m,n;
        cin>>n;
        vi v(n);
        cin>>v;
        map<ll,ll> co,count;
        for(i=0;i<n;i++)
        {
            co[v[i]]=1;
        }
        j=1;
        for(auto i:co)
        {
            co[i.F]=j;j++;
        }
        for(i=0;i<=100000;i++)
            a[i]=-1;
        build(1,0,N-5);
        ll ans=0;
        for(i=0;i<n;i++)
        {
            ll y=co[v[i]];
            ll x=query(1,0,N-5,0,y-1);
            if(x==-1)
            {
                // cout<<i<<endl;
                ans++;
                count[y]++;
                update(1,0,N-5,y,y);
                continue;
            }
            // cout<<i<<" "<<count[y]<<endl;
            count[x]--;
            count[y]++;
            if(count[x]==0)
            {
                // count[y]--;
                update(1,0,N-5,x,-1);
                update(1,0,N-5,y,y);
                continue;
            }
            update(1,0,N-5,y,y);
        }
        cout<<ans;
    }
    return 0;
}