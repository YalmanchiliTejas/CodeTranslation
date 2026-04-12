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
#define N  1000005

int main()
{
    ios;
    ll tt=1;
    // cin>>tt;
    while(tt--)
    {
    	ll i,j,k,l,m,n;
    	string s;
    	cin>>s;
    	if(s=="AAA"||s=="BBB")
    		cout<<"No";
    	else
    		cout<<"Yes";
    }
    return 0;
}