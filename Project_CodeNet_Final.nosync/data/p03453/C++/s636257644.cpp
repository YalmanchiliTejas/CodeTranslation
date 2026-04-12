#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9,MOD=1e9+7,LINF=1e18;
struct E{int to,di;};
typedef pair<int,int> P;
/*
ダイクストラそれぞれ回してds[i]:sからの最短距離、dt[i]:tからの最短距離を作ってやる
各点へのs,tからの行き方が何通りあるかはdpで求められる(それぞれdps[i],dpt[i])
早い順にやってあげれば良さそう
ちょうど最短距離の半分の時に被るのが何通りかを数え上げて引いてやればいい
つまり？
その道を通るのが何通りかを調べてやれば終わり？
だから、
int sum_time=ds[t];
int ans=dps[t]*dps[t];
for(auto u,v,d edge){
  if(dps[u]<=sum_time/2<=dps[v])ans-=dps[u]*dpt[v];
}
*/
/*
なんでWAが出るのか　考察が間違っているのかな
最短経路の２乗-ぶつかるやつって考え方はあってると思う
最短経路がいつくあるかは流石に数えられている？各点へのそれが求められているから大丈夫なはず
そーとしてあるから足し損ねとかもなさそう
ぶつかるやつの数え損ね、数え過ぎがある？
点でぶつかるならその点はちょうど中間に位置していないといけない
つまりその点に辿りつくのにどっちから言ってもsum_time/2
この時削られるのは　あー分かったかも？
*/
int ds[123456],dt[123456],dps[123456],dpt[123456];

signed main(){
  int N,M,s,t;cin>>N>>M>>s>>t;s--;t--;
  vector<E> edge[N];
  for(int i=0;i<M;i++){
    int u,v,d;cin>>u>>v>>d;u--;v--;
    edge[u].push_back({v,d});
    edge[v].push_back({u,d});
  }
  for(int i=0;i<123456;i++)ds[i]=dt[i]=LINF;
  ds[s]=dt[t]=0;
  priority_queue<P,vector<P>,greater<P>> que;
  que.push(P(0,s));
  while(que.size()){
    P p=que.top();que.pop();
    int d=p.first,u=p.second;
    if(ds[u]<d)continue;
    for(auto q:edge[u]){
      if(ds[q.to]>ds[u]+q.di){
        ds[q.to]=ds[u]+q.di;
        que.push(P(ds[q.to],q.to));
      }
    }
  }
  que.push(P(0,t));
  while(que.size()){
    P p=que.top();que.pop();
    int d=p.first,u=p.second;
    if(dt[u]<d)continue;
    for(auto q:edge[u]){
      if(dt[q.to]>dt[u]+q.di){
        dt[q.to]=dt[u]+q.di;
        que.push(P(dt[q.to],q.to));
      }
    }
  }
  int sum_time=ds[t];
  vector<P> w(N);
  for(int i=0;i<N;i++)w[i]=P(ds[i],i);
  sort(w.begin(),w.end());
  dps[s]=1;
  for(int i=0;i<N;i++){
    int a=w[i].second;
    for(auto p:edge[a])
      if(ds[a]+p.di==ds[p.to])
        dps[p.to]+=dps[a],dps[p.to]%=MOD;
  }
  for(int i=0;i<N;i++)w[i]=P(dt[i],i);
  sort(w.begin(),w.end());
  dpt[t]=1;
  for(int i=0;i<N;i++){
    int a=w[i].second;
    for(auto p:edge[a])
      if(dt[a]+p.di==dt[p.to])
        dpt[p.to]+=dpt[a],dpt[p.to]%=MOD;
  }
  assert(dps[t]==dpt[s]);
  int ans=(dps[t]*dpt[s])%MOD;
  //cout<<ans<<endl;
  /*
  for(int i=0;i<N;i++)cout<<ds[i]<<" ";cout<<endl;
  for(int i=0;i<N;i++)cout<<dt[i]<<" ";cout<<endl;
  for(int i=0;i<N;i++)cout<<dps[i]<<" ";cout<<endl;
  for(int i=0;i<N;i++)cout<<dpt[i]<<" ";cout<<endl;
  */
  for(int i=0;i<N;i++){
    if(ds[i]*2==sum_time&&dt[i]*2==sum_time){
      int a=(dps[i]*dpt[i])%MOD;
      ans-=(a*a)%MOD;
      ans+=MOD;ans%=MOD;
      assert(ans>=0&&ans<MOD);
      continue;
    }
    for(auto p:edge[i]){
      if(ds[i]*2<sum_time&&ds[p.to]*2>sum_time&&dt[p.to]+ds[i]+p.di==sum_time){
        //cout<<i<<" "<<p.to<<endl
        int a=(dps[i]*dpt[p.to])%MOD;
        ans-=(a*a)%MOD;
        ans+=MOD;ans%=MOD;
        assert(ans>=0&&ans<MOD);
      }
    }
  }
  cout<<ans<<endl;
}
