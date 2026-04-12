#include<bits/stdc++.h>
using namespace std;
#define int long long

struct UnionFind{
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};

typedef pair<int,int> P;
typedef pair<int,P> PP;
bool used[314514];
signed main(){
  int n;
  cin>>n;
  vector<P> v(n),u(n);
  for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
  for(int i=0;i<n;i++) u[i]=P(v[i].second,v[i].first);
  sort(v.begin(),v.end());
  sort(u.begin(),u.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  u.erase(unique(u.begin(),u.end()),u.end());
  //for(P p:v) cout<<p.first<<" "<<p.second<<endl;
  n=v.size();
  map<P,int> m;
  for(int i=0;i<n;i++) m[v[i]]=i;
  map<int,int> mx,my;
  int cx=0,cy=0;
  priority_queue<PP,vector<PP>,greater<PP> > q;
  for(int i=0;i<n;i++){
    if(!mx.count(v[i].first)) mx[v[i].first]=cx++;
    if(!my.count(u[i].first)) my[u[i].first]=cy++;
  }
  for(int i=0;i<n;i++){
    //cout<<mx[v[i].first]<<" "<<my[v[i].second]<<endl;
    q.push(PP(0,P(i,n+mx[v[i].first])));
    q.push(PP(0,P(i,n+cx+my[v[i].second])));
  }
  for(int i=0;i<n-1;i++){
    if(v[i].first==v[i+1].first) continue;
    q.push(PP(abs(v[i].first-v[i+1].first),
	      P(n+mx[v[i].first],n+mx[v[i+1].first])));
  }
  for(int i=0;i<n-1;i++){
    if(u[i].first==u[i+1].first) continue;
    q.push(PP(abs(u[i].first-u[i+1].first),
	      P(n+cx+my[u[i].first],n+cx+my[u[i+1].first])));
  }
  //cout<<n<<" "<<cx<<" "<<cy<<endl;
  int ans=0;
  UnionFind uf(n+cx+cy);
  while(!q.empty()){
    PP pp=q.top();q.pop();
    P p=pp.second;
    int d=pp.first,s=p.first,t=p.second;
    //cout<<d<<" "<<s<<" "<<t<<endl;
    if(uf.same(s,t)) continue;
    //cout<<d<<" "<<s<<" "<<t<<endl;
    ans+=d;
    uf.unite(s,t);
  }
  cout<<ans<<endl;
  return 0;
}
