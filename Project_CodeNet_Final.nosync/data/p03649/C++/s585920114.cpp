#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  priority_queue<ll>que;
  for(int i=0;i<n;i++){
    ll a;cin>>a;
    que.push(a);
  }
  ll ans=0;
  while(1){
    if((que.top())<n)break;
    ll num=que.top();
    que.pop();
    ll cnt=(num)/n;
    num-=((num)/n)*n;
    vi numm;numm.pb(num);
    ans+=cnt;
    for(int i=0;i<n-1;i++){
      numm.pb(cnt+que.top());
      que.pop();
    }
    for(int i=0;i<n;i++){que.push(numm[i]);}
  }
  cout<<ans<<endl;
  return 0;
}
