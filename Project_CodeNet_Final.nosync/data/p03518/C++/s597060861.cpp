#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#ifdef BTK
#include<dvector.h>
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define DEBUG if(0)
#endif

#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
int N;
typedef vector<int> V;
V ret;
int bg=0;

V f(V p,int k){
    FOR(i,k,N)swap(p[i],p[i-k]);
    return p;
}
V rt(V v){
    bg=(bg+1)%N;
    ret.pb(1);
    return f(v,1);
}
V sw(V v){
    ret.pb(N-1);
    return f(v,N-1);
}

bool check(V v){
    REP(i,N-1)if(v[i]>v[i+1])return false;
    return true;
}
typedef pair<int,V> X;
int main(){
    cin>>N;
    V in(N);
    REP(i,N)in[i]=N-i-1;
#ifndef BTK
    cin>>in;
#endif


    while(check(in)==false){
        if(bg==0)in=rt(in);
        else if(in.front()<in.back())in=sw(in);
        else in=rt(in);
    }
    
    cout<<ret.size()<<endl;
#ifndef BTK
    for(auto &it:ret)cout<<it<<endl;
#endif
    return 0;
}
