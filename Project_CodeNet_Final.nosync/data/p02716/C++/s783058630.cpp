#include <bits/stdc++.h> // ver2.6.3
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define VVi vector<Vi>
#define VVVi vector<VVi>
#define Vm vector<mint>
#define Vs vector<string>
#define Vd vector<double>
#define Pii pair<int,int>
#define Pdd pair<double,double>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define VTiii vector<Tiii>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define FI first
#define SE second
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define INF 3000000000000000000 // 3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define MOD 1000000007 // 10^9 + 7

using namespace std;

Vi vis(Vi &v){Vi S(v.size()+1);rep(i,1,S.size())S[i]+=v[i-1]+S[i-1];return S;} // 累積和

vector<vector<Pii>> gr;
Vi dist;
vector<int> prever;

void shortest(int s){
  int n = gr.size();
  dist = Vi(n);
  prever = vector<int>(n,-1);
  rep(i,0,n) dist[i]=INF;
  dist[s] = 0;
  
  priority_queue<Tiii,vector<Tiii>,greater<Tiii>> q;
  q.push(make_tuple(0,s,-1));
  while(!q.empty()){
    int nowdist,now,past;
    tie(nowdist,now,past)=q.top();
    q.pop();
    if(nowdist>dist[now]) continue;
    dist[now]=nowdist;
    rep(i,0,gr[now].size()){
      int next=gr[now][i].first,cost=gr[now][i].second;
      if(next!=past && nowdist+cost<dist[next]){
        prever[next] = now; // テスト
        q.push(make_tuple(nowdist+cost,next,now));
        dist[next]=nowdist+cost;
      }
    }
  }
  return;
}

vector<int> get_path(int t){ //頂点tへの最短路
  vector<int> path;
  for(;t!=-1;t=prever[t]){
    path.push_back(t);
  }
  reverse(path.begin(), path.end());
  return path;
}

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n;
  cin >> n;
  Vi a(n);
  Vin(a);
  reverse(ALL(a));
  
  if(n%2==0){
    Vi L(n/2),R(n/2);
    int m = n/2;
    rep(i,0,m){
      L[i] = a[i*2];
      R[i] = a[i*2+1];
    }
    reverse(ALL(R));
    L = vis(L);
    R = vis(R);
    reverse(ALL(R));
    //cout << L << endl << R << endl;
    int ans = -INF;
    rep(i,0,L.size()){
      ans = max(ans,L[i]+R[i]);
    }
    cout << ans << endl;
  }
  else {
    int V = ((n-1)/2)*3;
    //graph gr(V+1);
    gr.resize(V+1);
    int now = 0;
    gr[1].pb(mp(0,0));
    gr[2].pb(mp(1,0));
    //gr.add_edge(0,1,0);
    //gr.add_edge(1,2,0);
    
    rep(i,0,V){
      if(i%3==0){
        //gr.add_edge(i,min(i+3,V),-a[now]);
        //gr.add_edge(i,min(i+4,V),-a[now]);
        gr[min(i+3,V)].pb(mp(i,-a[now]));
        gr[min(i+4,V)].pb(mp(i,-a[now]));
        now++;
      }
      else if(i%3==1){
        //gr.add_edge(i,min(i+3,V),-a[now]);
        //gr.add_edge(i,min(i+4,V),-a[now]);
        gr[min(i+3,V)].pb(mp(i,-a[now]));
        gr[min(i+4,V)].pb(mp(i,-a[now]));
        now++;
      }
      else {
        //gr.add_edge(i,min(i+3,V),-a[now]);
        gr[min(i+3,V)].pb(mp(i,-a[now]));
      }
    }
    
    int ans = -INF;
    shortest(V);
    //gr.dijkstra(0);
    ans = max(ans,-dist[0]);
    cout << ans << endl;
  }
  return 0;
}