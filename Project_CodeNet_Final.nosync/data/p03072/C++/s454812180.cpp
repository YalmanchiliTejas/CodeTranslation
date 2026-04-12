#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<unistd.h>
#include <array>
#include <map> 
#define ALL(a)  (a).begin(),(a).end()
const long long INF = 1000000007;

//いろんなstlの使い方　https://qiita.com/tukejonny/items/f4013547df761a0b3523
//http://y-mazun.hatenablog.com/entry/20111202/1322840281



using namespace std;
typedef long long ll;
struct point{
  int x;
  int y;

};
int gcd(int a, int b)
{
  if(a>b){
    return gcd(b,a);
  }
	return a == 0 ? b : gcd(b % a, a);
}
int lcm( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm
int input(){
  int x;
  cin>>x;
  return x;
}

int moji(char in)
{
    int ans = (int)in-(int)'a';
    if((ans < 0) || (ans > 25)){
        ans = 26;
    }
    return ans;
}
const int VV=1;//場合に応じてVVの値のみ変更する必要あり
//dijkstra(s)sがスタート地点でそこからの最短距離を配列dで表す。正の重みのみ使用可能
int cost[VV][VV];
int d[VV];
bool used[VV];
void dijkstra(int s){
  
  fill(d,d+VV,100000);
  fill(used,used+VV,false);
  d[s]=0;
  while(true){
    cout<<"Hello"<<endl;
    int v=-1;
    for(int u=0;u<VV;u++){
      if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
    }
    if(v==-1)break;
    used[v]=true;
    for(int u=0;u<VV;u++){
      d[u]=min(d[u],d[v]+cost[v][u]);
    }
  }

}

int compare_int(const void *a, const void *b)//qsort(quick sort利用時に使用)
{
    return *(int*)a - *(int*)b;
}

int binary_searchh(long long x,long long k[],int n){
  int l=0;
  int r=n;
  while(r-l>=1){
    int i=(l+r)/2;
    if(k[i]==x)return i;
    else if(k[i]<x)l=i+1;
    else r=i;
  }
  return -1;
}

struct File {
    int aa;
    int bb;

    File(const int& aa, const int& bb)
        : aa(aa), bb(bb) {}
};

bool operator<(const File& a, const File& b)
{
    // ファイル種別、ファイル名の順番で優先順位を付けて比較
    return std::tie(a.aa, a.bb) < std::tie(b.aa, b.bb);
}

long long kaijo(long long x){
  long long l=10*10*10*10*10*10*10*10*10+7;
  long long sum=1;
  for(int i=x;i>0;i--){
    sum*=i;
    if(sum>l){
      sum%=l;
    }
  }
  return sum;
}


template<class T>void chmin(T &a,T b){
  if(a>b){
    a=b;
  }
}

//formerは前方のindex(自分自身を含んで良い)
template<class T>int former(const vector<T>&v,T x){
  return upper_bound(v.begin(),v.end(),x)-v.begin()-1;
}
//latterは後方のindex(自分自身を含んで良い)
template<class T>int latter(const vector<T>&v,T x){
  return lower_bound(v.begin(),v.end(),x)-v.begin();
}

struct UnionFind{
  //par[i]データiの属する木の親の番号。i==par[i]のときデータiは木の根ノードである
  vector<int>par;
  //sizes[i]:根ノードiの木に含まれるデータ数、iが根ノードでないときは無意味な値になる
  vector<int>sizes;

  UnionFind(int n):par(n),sizes(n,1){
    //最初は全てのデータiがグループiに存在するものとして初期化
    for(int i=0;i<n;i++){
      par[i]=i;
    }
  }
  //データxが属する木の根を得る
  int find(int x){
    if(x==par[x]){
      return x;
    }
    return par[x]=find(par[x]);

  }
  //2つのデータx,yが属する木をマージする
  void unite(int x,int y){
    //データの根ノードを得る
    x=find(x);
    y=find(y);
    //もしすでに同じ木に属しているならマージの必要はない
    if(x==y){
      return;
    }
    //xの木がyの木よりも大きくなるようにする
    if(sizes[x]<sizes[y]){
      swap(x,y);
    }
    //xがyの親になるように連結する
    par[y]=x;
    sizes[x]+=sizes[y];
    
  }
  //2つのデータx,yが属する木が同じならtrueを返す
  bool same(int x,int y){
    return find(x)==find(y);
  }
  //データxが含まれる木の大きさを返す
  int size(int x){
    return sizes[find(x)];
  }

};

//クラスカル法
//頂点a,bをつなぐコストcostの（無向）辺
struct Edge{
  int a,b,cost;
  //コストの大小で順序定義
  bool operator<(const Edge& o)const{
    return cost<o.cost;
  }
};
//頂点数と辺集合の組として定義したグラフ
struct Graph{
  int n;//頂点数
  vector<Edge>es;//辺集合
  //クラスカル法で無向最小全域木のコストの和を計算する
  //グラフが非連結の時は最小全域森のコストの和になる
  //使い方http://dai1741.github.io/maximum-algo-2012/docs/minimum-spanning-tree/
  int kruskal(){
    //コストが小さい順にソーと
    sort(es.begin(),es.end());
    UnionFind uf(n);
    int min_cost=0;
    for(int ei=0;ei<es.size();ei++){
      Edge& e=es[ei];
      if(!uf.same(e.a,e.b)){
        //その辺によって2つの木が連結される
        min_cost+=e.cost;
        uf.unite(e.a,e.b);

      }
    }
    return min_cost;
  }
};
//標準入力からグラフを読み込む
Graph input_graph(){
  Graph g;
  int m;
  cin>>g.n>>m;
  for(int i=0;i<m;i++){
    Edge e;
    cin>>e.a>>e.b>>e.cost;
    g.es.push_back(e);
  }
  return g;
}
long long labs(long long x){
  if(x<0){
    return -x;
  }
  return x;
}




int main() {
  int N;
  cin>>N;
  int H[N];
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  int sum=0;
  int max=H[0];
  for(int i=0;i<N;i++){
    if(max<=H[i]){
      sum++;
      max=H[i];
    }
  }
  cout<<sum<<endl;

  
}

  


