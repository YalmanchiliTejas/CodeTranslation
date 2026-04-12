#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repx(i,a,b,x) for(ll i=a;i<b;i+=x)
#define rev(i,a,b) for(ll i=a;i>b;i--)
#define revx(i,a,b,x) for(ll i=a;i>b;i-=x)
#define arep(it,v) for(auto it=v.begin();it!=v.end();it++)
#define wh1(n) rep(xy1,0,n)
#define wh2(n) rep(xy2,0,n)
#define wh3(n) rep(xy3,0,n)
#define sc(i) cin>>i
#define ssc(i,j) sc(i);sc(j)
#define sssc(i,j,k) ssc(i,j);sc(k)
#define pf(i) cout<<i<<" "
#define pfn(i) cout<<i<<endl
#define cvec(v,n) rep(abc,0,n){ll xyz;sc(xyz);v.pb(xyz);}
#define pvec(v,n) rep(abc,0,n){pf(v[abc].F);pf(v[abc].S);}pfn("")
#define pll pair<ll,ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define spll set<pll>
#define vpll vector<pll>
#define vvll vector<vll>
#define vvpll vector<vpll>
#define pq(a) priority_queue<a>
#define pqc(a,cmp) priority_queue<a,vector<a>,cmp>
#define F first
#define S second
#define B begin
#define E end
#define R return
#define mp make_pair
#define pb push_back
#define ln length()
#define to_s to_string
#define Sort(v) sort(v.begin(),v.end())
#define Scmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define zero_arr(v) memset(v,0,sizeof(v))
#define update_map(m,i) if(m.find(i)!=m.end()){m[i]++;}else{m[i]=1;}
#define update_mapx(m,i,x) if(m.find(i)!=m.end()){m[i]+=x;}else{m[i]=x;}
#define M 1000000007
#define INF 2000000000
#define fast ios::sync_with_stdio(0); cin.tie(0)
int main(){
    fast;
    ll x,y,z;
    sssc(x,y,z);
    x=100*x+10*y+z;
    if(x%4){
        pfn("NO");
    }else{
        pfn("YES");
    }
    R 0;
}