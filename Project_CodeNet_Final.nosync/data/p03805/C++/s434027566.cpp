#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
struct edge{
    ll p;//点
    ll w;//辺の重み*-1
};
vector<vector<edge> > graph(100000);
vector<ll> res(100000);
ll v,e,r;//vは頂点,eは辺,rは始点
void dijkstra(){
  for(int i = 0;i < v;i++)res[i] = pow(10,18);
    res[r] = 0;
    priority_queue<pair<ll,ll> > que;//重み、頂点
    que.push(make_pair(0,r));
    while(!que.empty()){
        edge now;
        now.p = que.top().second;
        now.w = que.top().first * -1;
        que.pop();
        if(res[now.p] < now.w)continue;
        for(int i = 0;i < graph[now.p].size();i++){
            if(res[graph[now.p][i].p] > now.w + graph[now.p][i].w){
                res[graph[now.p][i].p] = now.w + graph[now.p][i].w;
                que.push(make_pair(res[graph[now.p][i].p] * -1,graph[now.p][i].p));
            }
        }
    }
}
int main(){
  cin >> v >> e;
  for(int i = 0;i < e;i++){
        ll a,b,c;
        cin >> a >> b;//マイナスするか?気をつける
        c = 1;
        a--,b--;
        edge memoa = {b,c};
        edge memob = {a,c};
        graph[a].push_back(memoa);
        graph[b].push_back(memob);//無向グラフのときはこれを追加
   }
  vector<vector<ll>> cost(v,vector<ll>(v));
  for(int i = 0;i < v;i++){
    r = i;
    dijkstra();
    for(int j = 0;j < v;j++)cost[i][j] = res[j];
  }
  vector<int> num(v);
  for(int i = 0;i < v;i++)num[i] = i;
  ll res = 0;
  do{
    if(num[0] != 0)break;
    ll now = 0;
    for(int i = 1;i < v;i++){
      now += cost[num[i]][num[i - 1]];
    }
    //for(int i = 0;i < v;i++)cout << num[i];
      //cout << endl;
    //cout << now << endl;
    if(now == v - 1){
      res++;
      //for(int i = 0;i < v;i++)cout << num[i];
      //cout << endl;
      //cout << now << endl;
    }
    //cout << endl;
  }while(next_permutation(num.begin(),num.end()));
  cout << res << endl;
}