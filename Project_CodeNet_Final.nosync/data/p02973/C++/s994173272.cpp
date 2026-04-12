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
int main(){
    int n;
    cin>>n;
    vi vec(n);
    cin>>vec;
    multiset<int> se;
    REP(i,n){
        auto itr=se.lower_bound(vec[i]);
        if(itr==se.begin()){
            se.insert(vec[i]);
        }else{
            se.erase(--itr);
            se.insert(vec[i]);
        }
    }
    cout<<se.size()<<endl;
    return 0;
}