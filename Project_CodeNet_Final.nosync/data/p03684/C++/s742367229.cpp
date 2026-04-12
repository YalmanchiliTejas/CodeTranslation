#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
#define DEBUG if(false)

const int INF = 2000000000;

template <typename T>
int indexOf(vector<T> v, T elem)
{
  auto iter = find(v.begin(), v.end(), elem);
  size_t idx = distance(v.begin(), iter);
  if (idx == v.size()) return -1;
  return idx;
}

const int MAX_N=100000;
int n;
struct city {
  int i,x,y;
};

struct edge {
  int from, to, cost;
};

vector<city> cities;
vector<edge> v;//全ての辺の集合
vector<edge> f;//最小全域木

// * begin union find
int tree[MAX_N],//木を管理する配列，インデックスがノード，値が木のID
    tree_rank[MAX_N]={};//木の高さを管理する配列，インデックスが木のID，値が高さ

void init()
{
  // 最初は全ての要素が別の木に属する
  FORI(n){
    tree[i]=i;
  }
}

//木の根を探す関数
int root(int i)//i:ノードID
{
  if(tree[i]==i)return i;//根
  else return tree[i]=root(tree[i]);//親ノードを探す&経路圧縮
}

//ノードが同じ木に属するか否か
bool sameTree(int i,int j)//i,j:ノードID
{
  return root(i)==root(j);
}

// 木を統合
void unite(int i,int j)
{
  i=root(i);j=root(j);
  if(i==j)return;
  if(tree_rank[i]<tree_rank[j]){
    tree[i]=j;
  }else{
    tree[j]=i;
    if(tree_rank[i]==tree_rank[j])tree_rank[i]++;
  }
}
// * end union_find

int main(int, char const*[])
{
  cin>>n;
  cities=vector<city>(n);
  FORI(n){
    int x,y;
    cin>>x>>y;
    cities[i]=city{i,x,y};
  }

  //グラフ構築
  sort(cities.begin(), cities.end(), [](city lhr, city rhr) {
      return lhr.x<rhr.x;
      });
  for(int j=0;j<n-1;j++){
    v.push_back(edge{cities[j].i,cities[j+1].i,cities[j+1].x-cities[j].x});
  }
  sort(cities.begin(),cities.end(), [](city l,city r){
      return l.y<r.y;
      });
  for(int j=0;j<n-1;j++){
    v.push_back(edge{cities[j].i,cities[j+1].i,cities[j+1].y-cities[j].y});
  }

  //クラスカル法
  sort(v.begin(), v.end(), [](edge l,edge r){
      return l.cost<r.cost;
  });
  init();//union find初期化
  for(edge e:v){
    if(sameTree(e.from, e.to)){
      continue;//点が既に繋がっていたら辺を捨てる
    }
    f.push_back(e);
    unite(e.from, e.to);
  }

  DEBUG for(edge e:f)cout<<e.from<<"->"<<e.to<<":"<<e.cost<<endl;

  vector<int> costs(f.size());
  transform(f.begin(),f.end(),costs.begin(),[](edge e){
      return e.cost;
    });
  int cost=accumulate(costs.begin(),costs.end(),0);

  cout<<cost<<endl;

  return 0;
}
