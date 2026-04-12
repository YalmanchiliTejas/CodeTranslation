#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N = 100010;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(auto &t:a)cin>>t;return i;}
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T> void prArr(T a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

class UF{
public:
  int V;
  vector<int> par,rnk,sz;
  UF(){}
  UF(int V):V(V),par(V),rnk(V,0),sz(V,1){for(int i=0;i<V;i++)par[i]=i;}
  
  int find(int x){
    assert(x < V);
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    if(rnk[x]<rnk[y])par[x]=y, sz[y] += sz[x];
    else{
      par[y]=x;
      sz[x] += sz[y];
      if(rnk[x]==rnk[y])rnk[x]++;
    }
  }

  bool same(int x,int y){return find(x)==find(y);}

  int size(int x){return sz[find(x)];}
};

int mod_determinant(vector<vector<int> > A,const int mod = 1e9+7/*素数のみ使用可能*/){
  /*long longにしないと死ぬので注意*/
  auto mod_pow =[&](int x,int n){
    int res=1;
    while(n){
      if(n%2) res=res*x%mod;
      x=x*x%mod;
      n/=2;
    }
    return res;
  };
  
  int n = A.size();
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) A[i][j] = (A[i][j]%mod + mod) % mod;
  
  
  int det = 1;
  for(int i=0;i<n;i++){
    int pivot=-1;//次の基準となる添え字。
    for(int j=i;j<n && pivot==-1;j++) if(A[j][i]!=0) pivot=j;//0以外の1つを探す
    
    if(pivot == -1) return 0; // det = 0;
    swap(A[i],A[pivot]);//i行目に持ってくる。
    if(i != pivot) det = (-det + mod) % mod;
    det = det * A[i][i] % mod;
    
    int div = mod_pow(A[i][i],mod-2);
    for(int j=i+1;j<n;j++) A[i][j]=A[i][j]*div%mod; //左辺をA[i][i]で両辺を割る。
    
    for(int j=i+1;j<n;j++){ 
      for(int k=i+1;k<n;k++) A[j][k]=(A[j][k]-A[j][i]*A[i][k]%mod+mod)%mod;
      A[j][i] = 0;
    }
  }
  return det;
}

int calcL(vector<vector<int> > L){
  int n = L.size();
  vector<vector<int> > LL(n-1,vector<int>(n-1));

  for(int i=1;i<n;i++)
    for(int j=1;j<n;j++) LL[i-1][j-1] = L[i][j];
  return mod_determinant(LL);
}

vector<vector<int> > G;
int calc(UF &uf,int par){
  vector<int> num;
  int n = G.size();
  for(int i=0;i<n;i++) if(uf.find(i) == par) num.push_back(i);
  sort(num.begin(),num.end());
    
  int l = num.size();
  vector<vector<int> > L(l,vector<int>(l));
  for(int i:num)
    for(int to:G[i]){
      int a = lower_bound(num.begin(),num.end(),i) - num.begin();
      int b = lower_bound(num.begin(),num.end(),to) - num.begin();
      if(b == l || num[b] != to) continue;
      L[a][b]--;
      L[a][a]++;
    }      
  
  return calcL(L);
};


signed main(){
  int n,m;
  cin>>n>>m;
  typedef pair<int,P> PP;
  vector<PP> edge(m);
  G.resize(n);
  for(int i=0;i<m;i++){
    int s,t,d;
    cin>>s>>t>>d; s--,t--;
    edge[i] = PP(d,P(s,t));
    G[s].push_back(t);
    G[t].push_back(s);
  }
  sort(edge.begin(),edge.end());

  UF uf(n);
  int dis = 0;
  for(int i=0;i<m;i++){
    int idx = i;
    UF tmp = uf;
    dis = edge[idx].first;
    
    while(i<m && edge[idx].first == edge[i].first){
      int a,b; tie(a,b) = edge[i].second;
      tmp.unite(a,b);
      i++;
    }
    i--;
    if(tmp.size(0) == n) break;
    uf = tmp;
  }

  
  vector<int> par;
  for(int i=0;i<n;i++) if(uf.find(i) == i) par.push_back(i);

  int ans = 0;
  int p = par.size();
  for(int bit=0;bit<(1<<p);bit++){
    UF tmp = uf;
    
    for(int i=0;i<p;i++)
      for(int j=0;j<p;j++)
        if((bit>>i&1) == (bit>>j&1)) tmp.unite(par[i],par[j]);
    
    
    int cnt = 0;
    for(int i=0;i<n;i++) if(tmp.find(i) == i) cnt++;
    if(cnt != 2) continue;
    int num = 1;
    for(int i=0;i<n;i++) if(tmp.find(i) == i) num = num * calc(tmp,i)%mod;
    ans = (ans+num)%mod;
  }
  cout<<dis<<" "<<ans<<endl;
  return 0;
}

