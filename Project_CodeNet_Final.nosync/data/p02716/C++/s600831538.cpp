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
using namespace std;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
#define N  200005

ll n;
vi v;

vector<map<ll,ll>> ma(N);

ll solve(ll ind,ll x)
{
	if(ma[ind].find(x)!=ma[ind].end()) return ma[ind][x];
	ll y=n-ind;
	if(x<=0) 
	{
		ma[ind][x]=0;
		return 0;
	}
	if(ind>=n) 
	{
		ma[ind][x]=-peak;
		return -peak;
	}
	if((y+1)/2<x) 
	{
		ma[ind][x]=-peak;
		return -peak;
	}
	ll ans=v[ind]+solve(ind+2,x-1);
	y=solve(ind+1,x);
	ma[ind][x]=max(y,ans);
	return max(y,ans);
}

int main()
{
    ios;
    ll tt=1;
    // cin>>tt;
    while(tt--)
    {
    	ll i,j,k,l,m;
    	cin>>n;
    	for(i=0;i<n;i++)
    	{
    		cin>>l;
    		v.pb(l);
    	}
    	ll ans=solve(0,n/2);
    	cout<<ans;
    }
    return 0;
}