#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

struct cww{cww(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout<<fixed;
    cout<<setprecision(10);
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)

#define fi first
#define se second
#define pb push_back

template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}

template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
typedef vector<int> V;
typedef vector<V> VV;
int main(){
    int N,M;
    cin>>N>>M;
    VV g(N,V(N,0));
    REP(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a][b]=g[b][a]=1;
    }
    V seq(N-1);
    iota(seq.begin(),seq.end(),1);
    int res=0;
    do{
        int ans=1;
        if(!g[0][seq[0]])
           ans=0;
        REP(i,N-2){
            if(!g[seq[i]][seq[i+1]])
                ans=0;
        }
        res+=ans;
    }while(next_permutation(seq.begin(),seq.end()));
    cout<<res<<endl;

    return 0;
}
