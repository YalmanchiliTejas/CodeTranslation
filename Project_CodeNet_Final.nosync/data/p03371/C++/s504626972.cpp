#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;using vvi=vector<vi>;using vl=vector<ll>;
using P=pair<int,int>;using PL=pair<ll,ll>;using vp=vector<P>;
const int INF=1<<30,MOD=1000000007;const ll LINF=1ll<<60;
#define _ol3(_1,_2,_3,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...) _ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,v) REP(i,v.size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1ll<<(n))
#define clamp(n,mi,ma) max(min(n,ma),mi)
#define uniq(v) sort(all(v));v.erase(unique(all(v)),v.end())
#define pb push_back
#define F first
#define S second
#define endl '\n'
#ifndef LOCAL
struct ostdmy{template<class T>ostdmy&operator<<(const T&t){return*this;}};ostdmy cer_;
#define cerr cer_
#endif
#define cho(n,a,b) cout<<((n)?a:b)<<endl
#define YES(n) cho(n,"YES","NO")
#define Yes(n) cho(n,"Yes","No")
#define Poss(n) cho(n,"Possible","Impossible")
template<class T>bool chmax(T&a,const T&b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T&a,const T&b){if(a>b){a=b;return 1;}return 0;}
template<class T>ostream&operator<<(ostream&o,const vector<T>&v){for(const T&i:v)o<<i<<' ';return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(T&j:v)i>>j;return i;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<<p.F<<' '<<p.S;}
template<class T,class U>istream&operator>>(istream&i,pair<T,U>&p){return i>>p.F>>p.S;}
template<class T>ostream&operator<<(ostream&o,const set<T>&v){for(const T&i:v)o<<i<<' ';return o;}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int a,b,c;
    int x,y;
    cin>>a>>b>>c>>x>>y;
    int ab=min(c*2,a+b);
    int ans=0;

    int k;


    k=min(x,y);
    ans+=k*ab;
    x-=k;
    y-=k;

    if(x){
        ans+=min(ab,a)*x;
    }
    if(y){
        ans+=min(ab,b)*y;
    }
    cout<<ans<<endl;
    return 0;
}
