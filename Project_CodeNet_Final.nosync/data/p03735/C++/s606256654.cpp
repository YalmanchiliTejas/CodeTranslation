#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPR(i,n) for(int i=(n);i>=0;i--)
#define all(vec) vec.begin(),vec.end()
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using P=pair<ll,ll>;
using PP=pair<ll,P>;
using vp=vector<P>;
using vpp=vector<PP>;
using vs=vector<string>;
#define fi first
#define se second
#define pb push_back
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<typename A,typename B>istream&operator>>(istream&is,pair<A,B> &p){is>>p.fi>>p.se;return is;}
template<typename A,typename B>ostream&operator<<(ostream&os,const pair<A,B> &p){os<<"("<<p.fi<<","<<p.se<<")";return os;}
template<typename T>istream&operator>>(istream&is,vector<T> &t){REP(i,t.size())is>>t[i];return is;}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&t){os<<"{";REP(i,t.size()){if(i)os<<",";os<<t[i];}cout<<"}";return os;}
const ll MOD=1000000007LL;
const int INF=1<<30;
const ll LINF=1LL<<60;
ll s1(int n,const vp& vec){
    ll a=0,b=0;
    REP(i,n){
        if(max(vec[i].fi,vec[i].se)>max(vec[a].fi,vec[a].se)){
            a=i;
        }
        if(min(vec[i].fi,vec[i].se)<min(vec[b].fi,vec[b].se)){
            b=i;
        }
    }
    ll p=max(vec[a].fi,vec[a].se);
    ll q=min(vec[b].fi,vec[b].se);
    ll r=p;
    ll s=q;
    REP(i,n){
        chmin(r,max(vec[i].fi,vec[i].se));
        chmax(s,min(vec[i].fi,vec[i].se));
    }
    return abs(p-r)*abs(q-s); 
}
ll s2(int n,const vp& vec){
    ll a=0,b=0;
    REP(i,n){
        if(max(vec[i].fi,vec[i].se)>max(vec[a].fi,vec[a].se)){
            a=i;
        }
        if(min(vec[i].fi,vec[i].se)<min(vec[b].fi,vec[b].se)){
            b=i;
        }
    }
    if(a==b){
        return LINF;
    }
    ll p=max(vec[a].fi,vec[a].se);
    ll q=min(vec[b].fi,vec[b].se);
    ll r=min(min(vec[a].fi,vec[a].se),max(vec[b].fi,vec[b].se));
    ll s=max(min(vec[a].fi,vec[a].se),max(vec[b].fi,vec[b].se));
    REP(i,n){
        if(i==a||i==b){
            continue;
        }
        if(max(s,vec[i].fi)-min(r,vec[i].fi)>max(s,vec[i].se)-min(r,vec[i].se)){
            chmax(s,vec[i].se);
            chmin(r,vec[i].se);
        }else{
            chmax(s,vec[i].fi);
            chmin(r,vec[i].fi);
        }
    }
    return abs(p-q)*abs(r-s);
}
ll s3(int n,const vp& vec){
    ll a=0,b=0;
    REP(i,n){
        if(max(vec[i].fi,vec[i].se)>max(vec[a].fi,vec[a].se)){
            a=i;
        }
        if(min(vec[i].fi,vec[i].se)<min(vec[b].fi,vec[b].se)){
            b=i;
        }
    }
    if(a==b){
        return LINF;
    }
    ll p=max(vec[a].fi,vec[a].se);
    ll q=min(vec[b].fi,vec[b].se);
    ll r=min(min(vec[a].fi,vec[a].se),max(vec[b].fi,vec[b].se));
    ll s=max(min(vec[a].fi,vec[a].se),max(vec[b].fi,vec[b].se));
    REPR(i,n-1){
        if(i==a||i==b){
            continue;
        }
        if(max(s,vec[i].fi)-min(r,vec[i].fi)>max(s,vec[i].se)-min(r,vec[i].se)){
            chmax(s,vec[i].se);
            chmin(r,vec[i].se);
        }else{
            chmax(s,vec[i].fi);
            chmin(r,vec[i].fi);
        }
    }
    return abs(p-q)*abs(r-s);
}
int main(){
    int n;
    cin>>n;
    vp vec(n);
    cin>>vec;
    cout<<min({s1(n,vec),s2(n,vec),s3(n,vec)})<<endl;
    return 0;
}