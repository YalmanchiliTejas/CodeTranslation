/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAX=105;
const ll LIM=10000  ;
const ll INF=0x3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
ll N,W,w[MAX],v[MAX],ans,opt[5],b_idx=0;

ll main(){
    scanf("%lld%lld",&N,&W);
    for(ll i=0;i<n;i++){
        scanf("%lld%lld",&w[i],&v[i]);
        opt[w[i]-w[0]]=max(v[i],opt[w[i]-w[0]]);
    }
    for(ll i=1;i<=3;i++) if(opt[i]*(b_idx+w[0])>opt[b_idx]*(i+w[0])){
        b_idx=i;
    }

    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAX=400005;
const ll INF=(1ll<<63)-1;
const ll MOD=1e9+7;

ll N;
ll conn[MAX],chk[MAX],min_B,max_B,min_R,max_R,ans=INF;
char flag[MAX];
pll val[MAX];
void eval(){
    ans=min(ans,(val[max_R].first-val[min_R].first)*(val[max_B].first-val[min_B].first));
    //printf("%lld %lld %lld %lld %lld\n",val[min_R].first,val[max_R].first,val[min_B].first,val[max_B].first,(val[max_R].first-val[min_R].first)*(val[max_B].first-val[min_B].first));
    return;
}
ll setflag(ll x,char u){
    if(u=='R'){
        flag[x]='R';
        flag[conn[x]]='B';
    }
    else{
        flag[x]='B';
        flag[conn[x]]='R';
    }
    return conn[x];
}
int main(){
    scanf("%lld",&N);
    for(ll i=0;i<N;i++){
        ll t1,t2;
        scanf("%lld%lld",&t1,&t2);
        val[i*2]=make_pair(t1,i),val[i*2+1]=make_pair(t2,i);
        chk[i*2]=-1,chk[i*2+1]=-1;
    }
    sort(val,val+2*N);
    for(ll i=0;i<2*N;i++){
        if(chk[val[i].second]==-1){
            chk[val[i].second]=i;
        }
        else{
            conn[chk[val[i].second]]=i;
            conn[i]=chk[val[i].second];
            chk[val[i].second]=-1;
        }
    }
    if(N==1){
        printf("0\n");
        return 0;
    }
    if(conn[0]!=2*N-1){
        min_R=0,max_R=2*N-1;
        ll k1=setflag(min_R,'R');
        ll k2=setflag(max_R,'R');
        ll lim=max(k1,k2);
        min_B=INF,max_B=-INF;
        for(ll i=1;i<2*N-1;i++){
            if(flag[i]==0) setflag(i,'R');
            if(flag[i]=='B'){
                min_B=min(min_B,i);
                max_B=max(max_B,i);
            }
        }
        eval();
        for(ll i=max_B;i>lim;){
            ll t=setflag(i,'R');
            lim=max(lim,t);
            min_B=min(min_B,t);
            do{i--;}while(i>max(k1,k2)&&flag[i]=='R');
            max_B=i;
            eval();
        }
    }
    for(ll i=0;i<2*N;i++) flag[i]=0;
    min_R=0,max_B=2*N-1;
    min_B=INF,max_R=-INF;
    setflag(min_R,'R'),setflag(max_B,'B');
    for(ll i=1;i<2*N-1;i++){
        if(flag[i]==0) setflag(i,'R');
        if(flag[i]=='R') max_R=max(max_R,i);
        else min_B=min(min_B,i);
    }
    eval();
    printf("%lld\n",ans);
}
