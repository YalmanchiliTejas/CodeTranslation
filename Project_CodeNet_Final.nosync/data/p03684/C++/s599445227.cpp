#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

class UnionFindTree{
private:
  // indexの数の親ノード(ある集合の親を見つけたいときはここを直接参照せず、findを使う)
  vector<int> par;
  // indexを根とする木のランク
  vector<int> rank;
  // 集合のサイズ
  vector<int> cnts;
  // 木の最大値
  int treeSize;
public:
  UnionFindTree(int initTreeSize = 1000){
    // 引数で与えられた値を最大格納数とするUnionFindTreeの作成
    treeSize = initTreeSize;
    init(initTreeSize);
  }
  void init(int sz){
    par.clear(),rank.clear(),cnts.clear();
    treeSize=sz;
    for(int i = 0; i < sz; i++){
      par.push_back(i);
      rank.push_back(0);
      cnts.push_back(1);
    }
  }
  // 与えられた数が格納されている木のルートを探索
  int find(int x){  
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
  }
  // 和集合をとる。ただしここでは各集合の親の付け替えは起こらない
  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(rank[x] < rank[y]){
      par[x] = y;
      cnts[y]+=cnts[x];
    }
    else{
      par[y] = x;
      cnts[x]+=cnts[y];
      if(rank[y] == rank[x])rank[x]++;
    }
  }
  // xの属する集合のサイズ
  int getCnt(int x){
    return cnts[find(x)];
  }
  bool same(int x,int y){
    return find(x) == find(y);
  }
    
};


int N;
int X[100010];
int Y[100010];
vector<pair<int,pii> > events;
pair<int,pii> ydist[100010];
pii xsorted[100010];
pii ysorted[100010];
UnionFindTree uft(100010);

int main(){

    fastStream();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
        xsorted[i] = pii(X[i], i);
        ysorted[i] = pii(Y[i], i);
    }
    sort(xsorted, xsorted + N);
    sort(ysorted, ysorted + N);
    for(int i = 1; i < N; i++){
        int dist = xsorted[i].first - xsorted[i - 1].first;
        events.emplace_back(make_pair(dist, make_pair(xsorted[i].second, xsorted[i - 1].second)));
    }
    for(int i = 1; i < N; i++){
        int dist = ysorted[i].first - ysorted[i - 1].first;
        events.emplace_back(make_pair(dist, make_pair(ysorted[i].second, ysorted[i - 1].second)));
    }
    sort(events.begin(), events.end());
    ll cost = 0;
    for(auto e : events){
        pii p = e.second;
        if(uft.same(p.first, p.second)){
            continue;
        }
        else{
            uft.unite(p.first, p.second);
            cost += e.first;
            if(uft.getCnt(p.first) == N){
                break;
            }
        }
    }
    cout << cost << endl;

    return 0;
}
