#include <bits/stdc++.h>
#define MAX_N 6500000
#define rank Asdfiasofsad
#define int long long
using namespace std;


class UF{
public:
  vector<int> par,rank;
  UF(){
    par.resize(MAX_N),rank.resize(MAX_N);
    for(int i=0;i<MAX_N;i++)par[i]=i,rank[i]=0;
  }
  UF(int n){
    par.resize(n),rank.resize(n);
    for(int i=0;i<n;i++)par[i]=i,rank[i]=0;
  }

  int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y])par[x]=y;
    else{
      par[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }

  bool same(int x,int y){return find(x)==find(y);}
};

typedef pair<int,int> P;
typedef pair<int,P> PP;
vector<P> X,Y;
vector <PP> edge;
map<P,int> M;



int calc(){
  UF U;
  int res = 0;
  for(int i=0;i<edge.size();i++){
    int cost = edge[i].first;
    int a = edge[i].second.first;
    int b = edge[i].second.second;
    if(U.same(a,b)) continue;
    res += cost;
    U.unite(a,b);
  }
  return res;
}

signed main(){

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    if(M.count(P(x,y))){i--,n--;continue;}
    M[P(x,y)] = i;
    X.push_back(P(x,i));
    Y.push_back(P(y,i));
  }

  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());
  
  for(int i=0;i<n-1;i++){
    int cost = X[i+1].first - X[i].first;
    int a = X[i].second;
    int b = X[i+1].second;
    edge.push_back(PP(cost,P(a,b)));
  }


  for(int i=0;i<n-1;i++){
    int cost = Y[i+1].first - Y[i].first;
    int a = Y[i].second;
    int b = Y[i+1].second;
    edge.push_back(PP(cost,P(a,b)));
  }
  sort(edge.begin(),edge.end());
  cout<<calc()<<endl;
  return 0;
}
