#include<bits/stdc++.h>

#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define endl        '\n'
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
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

namespace InOp{
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
}
using namespace InOp;

namespace ModOp{
template<class x,class y,class z> z add(x a,y b,z m){return (a+b)%m;}
template<class x,class y,class z> z sub(x a,y b,z m){return (a-b+m)%m;}
template<class x,class y,class z> z mul(x a,y b,z m){return ((ll)a*b)%m;}
template<class y,class z> z expo(ll b,y e,z m){ll a=1;b%=m;while(e!=0){if((e&1)==1){a=a*b;a=a%m;}b=b*b;b%=m;e>>=1;}return a%m;}
template<class x,class z> z inv(x b,z m){return expo(b,m-2,m);}
template<class x,class y> x invGeneral(x a,y b){if(a==0)return b==1?0:-1;x m=invGeneral(b%a,a);return m==-1?-1:((1-(ll)b*m)/a+b)%b;}
template<class x,class y,class z> z div(x a,y b,z m){ll c=inv(b,m);return mul(a,c,m);}
}
using namespace ModOp;

namespace Debug{
template<class x> void deb(x a){cerr<<"a"<<": "<<a<<endl;}
template<class x,class y> void deb(x a,y b){cerr<<"a"<<": "<<a<<" | "<<"b"<<": "<<b<<endl;}
template<class x,class y,class z> void deb(x a,y b,z c){cerr<<"a"<<": "<<a<<" | "<<"b"<<": "<<b<<" | "<<"c"<<": "<<c<<endl;}
template<class x,class y,class z,class xy> void deb(x a,y b,z c,xy d){cerr<<"a"<<": "<<a<<" | "<<"b"<<": "<<b<<" | "<<"c"<<": "<<c<<" | "<<"d"<<": "<<d<<endl;}
}
using namespace Debug;

#define N  1000005

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll tt=1;
    // cin>>tt;
    while(tt--)
    {
        ll i,j,k,l,r,x,y,m,n;
        cin>>n;
        vi v(n);
        cin>>v;
        ll sum=0,ans=0;
        for(i=0;i<n;i++)
        {
            ans=(sum*v[i]+ans)%hell;
            sum=(sum+v[i])%hell;
        }
        cout<<ans;
    }
    return 0;
}