 
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
using msi=map<string,int>;
using mii=map<int,int>;
using psi=pair<string,int>;
using pii=pair<int,int>;
using vlai=valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define MOD ((ll)1e9+7)
void get(){}template<class H,class...T>void get(H&h,T&...t){cin>>h;get(t...);}
template<class T>void geti(T&a){for(auto&_:a)cin>>_;}
template<class T>void getii(T&a){for(auto&_:a)geti(_);}
void put(string d){}template<class H,class...T>void put(string d,H&h,T&...t){cout<<h;if(sizeof...(t))cout<<d;put(d,t...);}
template<class T>void puti(T&a,string d=" "){bool f=1;for(auto&_:a)cout<<(exchange(f,0)?"":d)<<_;cout<<endl;}
template<class T>void putii(T&a,string d=" "){for(auto&_:a)puti(_,d);}
#define dcl(...) int __VA_ARGS__;get(__VA_ARGS__)
#define dclt(t,...) t __VA_ARGS__;get(__VA_ARGS__)
template<class F,class S>void add(map<F,S>&mp,F f,S s){if(mp.find(f)==mp.end())mp[f]=F();mp[f]+=s;}
struct p{
    int x,y;
};
struct rect{
    p s,t;
};

void ume(vvi &f,int _y,int _x){
    queue<pii> q;
    q.emplace(_y,_x);
    while(!q.empty()){
        int y=q.front().fs;
        int x=q.front().sc;
        q.pop();
        vi vy;
        vi vx;
        if(y!=0)vy.pb(y-1);
        if(y+1!=f.size())vy.pb(y+1);
        if(x!=0)vx.pb(x-1);
        if(x+1!=f[0].size())vx.pb(x+1);
        for(auto Y:vy){
            if(f[Y][x]==0)q.emplace(Y,x);
            f[Y][x]=1;
        }
        for(auto X:vx){
            if(f[y][X]==0)q.emplace(y,X);
            f[y][X]=1;
        }
    }
}

int main(){
    int n;
    while(cin>>n,n){
        vi vx,vy;
        vector<rect> r(n);
        rep(i,n){
            dcl(sx,sy,tx,ty);
            sy=10000000-sy;
            ty=10000000-ty;
            r[i]={{sx,sy},{tx,ty}};
            vx.pb(sx);
            vx.pb(tx);
            vy.pb(sy);
            vy.pb(ty);
        }
        sort(all(vx));
        vx.erase(unique(all(vx)),vx.end());
        sort(all(vy));
        vy.erase(unique(all(vy)),vy.end());
        for(auto &d:r){
            d.s.x=lower_bound(all(vx),d.s.x)-vx.begin();
            d.t.x=lower_bound(all(vx),d.t.x)-vx.begin();
            d.s.y=lower_bound(all(vy),d.s.y)-vy.begin();
            d.t.y=lower_bound(all(vy),d.t.y)-vy.begin();
        }
        vvi f(vy.size()*2-1,vi(vx.size()*2-1,0));
        for(auto d:r){
            int sx=d.s.x*2;
            int tx=d.t.x*2;
            int sy=d.s.y*2;
            int ty=d.t.y*2;
            if(sx>tx){
                swap(sx,tx);
            }
            if(sy>ty){
                swap(sy,ty);
            }
            for(int i=sx;i<=tx;i++){
                f[sy][i]=f[ty][i]=1;
            }
            for(int i=sy;i<=ty;i++){
                f[i][sx]=f[i][tx]=1;
            }
        }
        for(int i=0;i<f.size();i++){
            if(f[i][0]==0) ume(f,i,0);
            if(f[i][f[0].size()-1]==0) ume(f,i,f[0].size()-1);
        }
        for(int i=0;i<f[0].size();i++){
            if(f[0][i]==0) ume(f,i,0);
            if(f[f.size()-1][i]==0) ume(f,f.size()-1,i);
        }
        int ans=0;
        rep(i,f.size())rep(j,f[0].size()){
            if(f[i][j]==0){
                ume(f,i,j);
                ans++;
            }
        }
        cout<<ans+1<<endl;
    }
}

