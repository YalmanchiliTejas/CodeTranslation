#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

#define MAX 200
#define INFTY (1<<30)

typedef vector<vector<int> > Matrix;
typedef long long ll;

#define MOD 1000000007

class DisjointSet{
    public:
    DisjointSet(){}
    DisjointSet( int size ){
        rank.resize( size, 0 );
        p.resize( size, 0 );
    }
    
    void makeSet( int x ){
        p[x] = x;
        rank[x] = 0;
    }
    
    void merge( int x, int y ){
        link( findSet(x), findSet(y) );
    }
    
    int findSet( int x ){
        if ( x != p[x] ) p[x] = findSet( p[x] );
        return p[x];
    }
    
    bool isSameSet( int x, int y ){
        return ( findSet(x) == findSet(y) );
    }
    
    private:
    vector<int> rank, p;
    
    void link ( int x, int y ){
        if ( rank[x] > rank[y] ){
            p[y] = x;
        } else {
            p[x] = y;
            if ( rank[x] == rank[y] ) rank[y]++;
        }
    }
};

class Edge{
    public:
    int source, target, cost;
    Edge( int source=0, int target=0, int cost=0 ):
    source(source), target(target), cost(cost){}
    bool operator < ( const Edge &e ) const{
        return cost < e.cost;
    }
};

int kruskal(int N, vector<Edge> edges){ // vector<Edge> &mst
  int lastCost = -1;
  sort( edges.begin(), edges.end() );
  
  DisjointSet dset = DisjointSet( N + 1);
  
  for ( int i = 0; i < N; i++ ) dset.makeSet( i );
  
  int source, target;
  for ( int i = 0; i < edges.size(); i++ ){
    Edge e = edges[i];
    if ( dset.findSet( e.source ) != dset.findSet( e.target ) ){
      lastCost = e.cost;
      dset.merge( e.source, e.target );
    }
  }
  return lastCost;
}

void dfs( Matrix G, int id, int u, int w, vector<int> &l, vector<int> &ID){
  ID[u] = id;
  l.push_back(u);
  for ( int v = 0; v < G.size(); v++ ){
    if ( ID[v] == -1 && G[u][v] < w ) dfs(G, id, v, w, l, ID);
  }
}

void printComps(vector<vector<int> > &comps){
  cout << comps.size() << " components" << endl;
  for ( int i = 0; i < comps.size(); i++ ){
    cout << i << ":";
    for ( int j = 0; j < comps[i].size(); j++ ) cout << " " << comps[i][j];
    cout << endl;
  }
}

void checkID(vector<vector<int> > &comps, vector<int> ID){
  int cnt = 0;
  for ( int i = 0; i < comps.size(); i++ ){
    for ( int j = 0; j < comps[i].size(); j++ ) {
      int v = comps[i][j];
      assert( ID[v] == i );
      cnt++;
    }
  }
  assert( cnt == ID.size() );
}

void initMatrix(Matrix &m){
  for ( int i = 0; i < m.size(); i++ ){
    for ( int j = 0; j < m[i].size(); j++ ) m[i][j] = 0;
  }
}


ll det(int n, int a[MAX][MAX], ll mod){
  rep(i, n) rep(j, n) assert( a[i][j] == a[j][i] );

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (; a[j][i] != 0; ans = -ans) {
	ll r = a[i][i] / a[j][i];
	for (int k = i; k < n; k++) {
	  ll t = (a[i][k] - r * a[j][k]) % mod;
	  a[i][k] = a[j][k];
	  a[j][k] = t;
	}
      }
    }
    ans = ans * a[i][i] % mod;
  }
  return (ans + mod) % mod;
}

bool isConnected(Matrix M, vector<int> nodes){
  queue<int> Q;
  int d[MAX];
  for ( int i = 0; i < M.size(); i++ ) d[i] = INFTY;

  Q.push(nodes[0]);
  d[nodes[0]] = 0;
  int u, v;
  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    for ( int v = 0; v < M.size(); v++ ){
      if ( M[u][v] && d[v] == INFTY ){
	d[v] = d[u] + 1;
	Q.push(v);
      }
    }
  }

  for ( int i = 0; i < nodes.size(); i++ ){
    if ( d[nodes[i]] == INFTY ) return false;
  }
  return true;
}

ll spCount(Matrix M, vector<int> IDM, vector<int> ID, int tgt, vector<int> nodes){
  int a[MAX][MAX];
  int deg[MAX];

  rep(i, M.size() ) deg[i] = 0;

  int ii = 0;
  rep(i, M.size() ){
    if ( IDM[ID[i]] != tgt ) continue;
    int jj = 0;
    rep(j, M.size() ){
      if ( IDM[ID[j]] != tgt ) continue;
      if ( i < j && M[i][j] ) {
	deg[ii]++;
	deg[jj]++;
      }
      a[ii][jj] = M[i][j]*(-1);

      jj++;
    }
    ii++;
  }

  rep(i, ii) a[i][i] = deg[i];

  assert(ii == nodes.size());

  ll d = det(ii-1, a, MOD);


  return d;
}

void solve(vector<Edge> edges, vector<vector<int> > G, vector<int> ID){
  int w = kruskal(G.size(), edges);

  cout << w << " ";
  vector<vector<int> > comps;
  rep(i, G.size()) ID[i] = -1;
  int id = 0;
  for ( int s = 0; s < G.size(); s++ ){
    if ( ID[s] == -1 ){
      vector<int> l;
      dfs(G, id++, s, w, l, ID);
      comps.push_back(l);
    }
  }
  
  vector<int> IDM; // comp index to A/B (0/1);
  Matrix A, B;
  A = B = G;
  int nc = comps.size();
  IDM.resize(nc);

  ll sum = 0;

  for ( int s = 1; s < (1<<nc)-1; s++ ){ // exclude 00000 and 11111
    vector<int> nodeA, nodeB;
    for ( int i = 0; i < nc; i++ ){
      IDM[i] = ((s & (1<<i))>0);
      if ( IDM[i] == 1 ) {
	for ( int j = 0; j < comps[i].size(); j++ ) nodeA.push_back(comps[i][j]);
      } else {
	for ( int j = 0; j < comps[i].size(); j++ ) nodeB.push_back(comps[i][j]);
      }
    }
    initMatrix(A);
    initMatrix(B);

    for ( int k = 0; k < edges.size(); k++ ){
      Edge e = edges[k];
      if ( IDM[ID[e.source]] == IDM[ID[e.target]] ){
	if ( IDM[ID[e.source]] == 1 ){
	  A[e.source][e.target] = A[e.target][e.source] = 1;
	} else {
	  assert( IDM[ID[e.source]] == 0);
	  B[e.source][e.target] = B[e.target][e.source] = 1;
	}
      }
    }

    ll cntA = spCount(A, IDM, ID, 1, nodeA);
    ll cntB = spCount(B, IDM, ID, 0, nodeB);

    sum = (sum + (cntA*cntB)%MOD ) % MOD;

  }

  cout << sum << endl;
}

int main(){
  int N, M, cost, source, target;
    
  cin >> N >> M;

  vector<vector<int> > G;
  vector<int> ID;
  
  rep(i, N) {
    vector<int> g;
    rep(j, N) g.push_back(INFTY);
    G.push_back(g);
    ID.push_back(-1);
  }
  
  vector<Edge> edges;
  for ( int i = 0; i < M; i++ ){
    cin >> source >> target >> cost;
    source--; target--;

    assert( 0 <= source && source < N);
    assert( 0 <= target && target < N);
    assert( 0 <= cost && cost <= 1000000000 );

    edges.push_back(Edge(source, target, cost));
    G[source][target] = G[target][source] = cost;
  }
  solve(edges, G, ID);

  return 0;
}