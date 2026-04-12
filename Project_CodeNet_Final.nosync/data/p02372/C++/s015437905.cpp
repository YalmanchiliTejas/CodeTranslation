#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define rep(i,n) for(int i = 0; i < n; ++i)
#define X first
#define Y second
#define all(x) x.begin(), x.end()
using namespace std;
using PII=pair<int,int>;

//g -> index, dist
vector<PII> g[200000];

// Tree
class Node{
  public:
    int value;
    int parent;
    Node(){value=0;};
    Node(int d){value=d;};
};

Node nodes[200000];
int used[20000];
int a, b, c, n;
int ans;
const int INF = 1000000000;

PII B1, B2;


// dist, index
PII dfs(int from, int to){
  PII mx(0,to);
//   cout << "index: " << to<< endl;
  rep(i, g[to].size()){
    if(from == g[to][i].X)continue;
    PII val = dfs(to, g[to][i].X);
    val.X += g[to][i].Y;
    if(mx.X <  val.X){
      mx = val;
    }
  }
  return mx;

//   cout << "mx.X " << mx.X << " " << mx.Y << endl;
//   cout << endl;
}

PII diameter(){
  B1 = dfs(-1,0);
  B2 = dfs(-1, B1.Y);
  return B2;
}

void dijkstra(int from, int to, vector<int>& d){
  vector<int> used;
  used.resize(n, 0);
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  pq.push(PII(0, from));
  d[from] = 0;

  while(!pq.empty()){
    int current = pq.top().Y;
    int d_sum = pq.top().X;pq.pop();

    if(d[current] < d_sum)continue;
//     cout << "current " << current << endl;

    rep(i, g[current].size()){
      //g -> index, dist
      int next = g[current][i].X;
      int cost = g[current][i].Y;

      if( d[next] > cost + d[current]){
        d[next] = cost + d[current];
        pq.push(PII(d[next] ,next));
      }
    }
  }
//   cout << "end" << endl;
}


int main(void){

  cin >> n;

  rep(i,n-1){
    cin >> a >> b >> c;
    if(a>b) swap(a,b);
    g[a].push_back(PII(b,c));
    g[b].push_back(PII(a,c));

    nodes[b].parent = a;
    nodes[b].value = c;
  }
//   cout << "end for" << endl;

  diameter();
//   cout << "dia" << endl;
  vector<int> d1, d2;
  d1.resize(n, INF);
  d2.resize(n, INF);
  dijkstra(B1.Y, B2.Y, d1);
  dijkstra(B2.Y, B1.Y, d2);

  rep(i,n){
     cout << max(d1[i], d2[i]) << endl;
  }

//   PII r = dfs(-1, 0);
//   cout << r.X << " " << r.Y << endl;
//   cout << endl;
//   PII t = dfs(-1, r.Y);
//   cout << t.X << " " << t.Y << endl;
//   cout << t.X << endl;
  

  return 0;
}