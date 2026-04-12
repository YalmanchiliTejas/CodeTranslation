#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ul=unsigned long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int n,s[500],t[500],ss[500][2],tt[500][2];
ul u[500],v[500],ans[500][500]={};
bool vis[500][500]={};
unsigned c{};
ul S(int i){
    if((u[i]>>c)&1u){
        if(s[i]) return 1;//exists 1
        else return 3;//forall 1
    }
    else{
        if(s[i]) return 2;//forall 0
        else return 0;//exists 0
    }
}
ul T(int j){
    if((v[j]>>c)&1u){
        if(t[j]) return 1;//exists 1
        else return 3;//forall 1
    }
    else{
        if(t[j]) return 2;//forall 0
        else return 0;//exists 0
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>n;
    fr(i,n) cin>>s[i];
    fr(j,n) cin>>t[j];
    fr(i,n) cin>>u[i];
    fr(j,n) cin>>v[j];
    for(;c<64;++c){
        fr(i,n) ss[i][0]=ss[i][1]=tt[i][0]=tt[i][1]=0;
        fr(i,n) fr(j,n){
            vis[i][j]=false;
            unsigned SS=S(i),TT=T(j);
            if(SS>>1u){
                vis[i][j]=true;
                ans[i][j]|=(SS&1ul)<<c;
                ++ss[i][SS&1u];
                ++tt[j][SS&1u];
            }
            if(TT>>1u){
                vis[i][j]=true;
                ans[i][j]|=(TT&1ul)<<c;
                ++ss[i][TT&1u];
                ++tt[j][TT&1u];

            }
            if((SS&1u)==(TT&1u)){
                vis[i][j]=true;
                ans[i][j]|=(SS&1ul)<<c;
                ++ss[i][SS&1u];
                ++tt[j][SS&1u];
            }
        }
        fr(i,n) fr(j,n) if(!vis[i][j]){
            if(S(i)){
                if(ss[i][1]){
                    ++ss[i][0];
                    ++tt[j][0];
                    continue;
                }
                if(!tt[j][0]&&tt[j][0]+tt[j][1]>=n-1){
                    ++ss[i][0];
                    ++tt[j][0];
                    continue;
                }
                ++ss[i][1];
                ++tt[j][1];
                ans[i][j]|=1ul<<c;
            }
            else{
                if(tt[j][1]){
                    ++ss[i][0];
                    ++tt[j][0];
                    continue;
                }
                if(!ss[i][0]&&ss[i][0]+ss[i][1]>=n-1){
                    ++ss[i][0];
                    ++tt[j][0];
                    continue;
                }
                ++ss[i][1];
                ++tt[j][1];
                ans[i][j]|=1ul<<c;
            }
        }
    }
    fr(i,n){
        ul tmp{};
        if(s[i]) fr(j,n) tmp|=ans[i][j];
        else{
            tmp=~0ul;
            fr(j,n) tmp&=ans[i][j];
        }
        if(tmp!=u[i]) return puts("-1"),0;
    }
    fr(j,n){
        ul tmp{};
        if(t[j]) fr(i,n) tmp|=ans[i][j];
        else{
            tmp=~0ul;
            fr(i,n) tmp&=ans[i][j];
        }
        if(tmp!=v[j]) return puts("-1"),0;
    }
    fr(i,n){
        fr(j,n) cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}