#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
 
int N,M,K;
int D[16];
int to[100][100];
int dist[1<<16];
const int INF=1001001001;
bool ok[100];
signed main(){
    cin>>N>>M>>K;
    rep(i,M)cin>>D[i],D[i]--;
    rep(i,N)rep(j,K)cin>>to[i][j],to[i][j]--;
 
    fill_n(ok,N,true);
    rep(i,M)ok[D[i]]=false;
 
    fill_n(dist,1<<M,INF);
    dist[(1<<M)-1]=0;
    queue<int>que;que.push((1<<M)-1);
    while(que.size()){
        int b=que.front();que.pop();
        rep(i,K){
            int nb=0;
            rep(j,M){
                if((b>>j&1)==0)continue;
                int nex=to[D[j]][i];
                if(ok[nex])continue;
                nex=find(D,D+M,nex)-D;
                nb|=(1<<nex);
            }
            if(dist[nb]<=dist[b]+1)continue;
            dist[nb]=dist[b]+1;
            que.push(nb);
        }
    }
    cout<<dist[0]<<endl;
    return 0;
}