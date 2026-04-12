#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ul = unsigned long long;
using vec = vector<int>;
using vec2 = vector<vec>;
vec s,t;
int n;
ul ans[510][510];
bool valid(vec x,vec y,vec2 &mp){
    rep(i,n){
        int m = mp[i][0];
        if(s[i])rep(j,n)m|=mp[i][j];
        else rep(j,n)m&=mp[i][j];
        if(m!=x[i])return false;
    }
    rep(j,n){
        int m = mp[0][j];
        if(t[j])rep(i,n)m|=mp[i][j];
        else rep(i,n)m&=mp[i][j];
        if(m!=y[j])return false;
    }
    return true;
}
bool solve(vec x,vec y,ul k){
    auto mp = vec2(n,vec(n,-1));
    rep(i,n)rep(j,n){
        if(x[i]^s[i])mp[i][j]=x[i];
        if(y[j]^t[j]){
            if((mp[i][j]^y[j])==1)return false;
            mp[i][j] = y[j];
        }
    }
    int cx=n,cy = n;
    rep(i,n)cx-=x[i]^s[i];
    rep(i,n)cy-=y[i]^t[i];
    if(cx > 1 and cy > 1){
        int cnt = 0;
        rep(i,n){
            if(!(x[i]^s[i])){
                int p = cnt++;
                rep(j,n)if(!(y[j]^t[j]))mp[i][j] = p++&1;
            }
        }
    }
    int c[2]={};
    if(cx == 1){
        rep(i,n)if(x[i]^s[i])c[x[i]]++;
        if(c[0] and c[1]){
            rep(i,n)rep(j,n)if(mp[i][j]==-1)mp[i][j]=(i+j)&1;
        }
        else{
            rep(i,n)rep(j,n){
                if(mp[i][j]==-1){
                    mp[i][j]=(c[t[j]]?x[i]:t[j]);
                }
            }
        }
    }
    else if(cy == 1){
        rep(i,n) if(y[i]^t[i])c[y[i]]++;
        if(c[0] and c[1]) {
            rep(i,n)rep(j,n)if(mp[i][j]==-1)mp[i][j] = (i+j)&1;
        }
        else{
            rep(i,n)rep(j,n){
                if(mp[i][j]==-1){
                    mp[i][j]=(c[s[i]]?y[j]:s[i]);
                }
            }
        }
    }
    if(!valid(x,y,mp))return false;
    rep(i,n)rep(j,n)ans[i][j] += k*mp[i][j];
    return true;
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    cin>>n;
    vector<ul> u(n),v(n);
    s.resize(n);t.resize(n);
    rep(i,n)cin>>s[i];rep(i,n)cin>>t[i];rep(i,n)cin>>u[i];rep(i,n)cin>>v[i];
    rep(_,64){
        vec x(n),y(n);
        rep(i,n)x[i]=u[i]&1,y[i]=v[i]&1,u[i]>>=1,v[i]>>=1;
        if(!solve(x,y,1ULL<<_)){
            cout<<-1<<endl;
            return 0;
        }
    }
    rep(i,n)rep(j,n){cout<<ans[i][j]<<" ";}cout<<endl;
}
            
