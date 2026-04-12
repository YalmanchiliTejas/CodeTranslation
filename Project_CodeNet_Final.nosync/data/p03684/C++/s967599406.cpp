#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"set"
#include"queue"
#include"map"
#include"string"
#include"cstring"
#include"iomanip"
using namespace std;
typedef long long ll;
struct vert
{
	ll x,y,no;
	bool operator<(const vert & ob)const
	{
		return x<ob.x;
	}
};
struct edge
{
	vert v1,v2;
	ll len;
	bool operator<(const edge & ob)const
	{
		return len<ob.len;
	}
};
bool comp(const vert &ob1,const vert &ob2)
{
	return ob1.y<ob2.y;
}
ll dist(vert u,vert v)
{
	return min(abs(v.x-u.x),abs(v.y-u.y));
}
const ll maxn=1e5+5;
ll pare[maxn];
ll find(ll x)
{
	return x==pare[x]?x:pare[x]=find(pare[x]);
}
void merge(ll x,ll y)
{
	pare[find(x)]=find(y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    vector<vert>vx(n),vy(n);
    for(ll i=0;i<n;++i)
    {
    	ll x,y;cin>>x>>y;
    	vert ob;ob.x=x;ob.y=y;ob.no=i;
    	vx[i]=ob;
    	vy[i]=ob;
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end(),comp);
    vector<edge>ed(2*(n-1));ll in=0;
    for(ll i=1;i<n;++i)
    {
    	 vert u=vx[i-1],v=vx[i];
    	 edge ob;ob.v1=u;ob.v2=v;
    	 ob.len=dist(u,v);
    	 u=vy[i-1];v=vy[i];
    	 edge ob1;ob1.v1=u;ob1.v2=v;
    	 ob1.len=dist(u,v);
    	 ed[in++]=ob;
    	 ed[in++]=ob1;
    }
    for(ll i=0;i<n;++i)    
    {
    	pare[i]=i;
    }
    sort(ed.begin(),ed.end());
    ll ans=0;
    for(ll i=0;i<2*(n-1);++i)
    {
    	edge ob=ed[i];
    	ll v1=ob.v1.no,v2=ob.v2.no;
    	if(find(v1)!=find(v2))
    	{
    		ans+=ob.len;merge(v1,v2);
    	}
    }
    cout<<ans<<'\n';
}









