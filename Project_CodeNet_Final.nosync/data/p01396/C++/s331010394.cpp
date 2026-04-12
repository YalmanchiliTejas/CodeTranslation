#include <set>
#include <iostream>
#include <cstdio>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

inline int getInt(){ int s; scanf("%d", &s); return s; }

using namespace std;

int w, h;
int m[1000][1000];

class Matching{
  typedef vector<vector<int> > G;

  vector<bool> visited;

  const G &g; //g[i][j] = k <==> i is connected to k
  int n;      //number of node
  int m;      //number of left node

  bool augment(int left) {
    if (left < 0)
      return true;
    if (visited[left])
      return false;
    visited[left] = true;
    REP(i, g[left].size()) {
      int right = g[left][i];
      if (augment(matching[right])) {
        matching[right] = left;
        return true;
      }
    }
    return false;
  }

public:
  vector<int> matching;

  explicit Matching(const G &graph, int mm)
    : g(graph), m(mm){
    n = graph.size();
  }

  int solve() {
    int matches = 0;
    matching = vector<int>(n,-1);
    visited  = vector<bool>(n);
    REP(left, m) {
      visited.assign(n, false);
      if (augment(left))
        matches++;
    }
    return matches;
  }
};

int main(){
  bool ans = true;

  h = getInt();
  w = getInt();

  REP(i,h) REP(j,w) m[i][j] = getInt();

  REP(cc, 2){
    vector<bool> memo(h);
    vector<vector<int> > g(h);

    REP(i,h) REP(j,h) if(i != j){
      bool ok = true;
      REP(k,w){
	if(m[i][k] <= m[j][k]){
	  ok = false;
	  break;
	}
      }
      if(ok) g[i].push_back(j);
    }

    // puts("g:"); REP(i,h) { printf("%d: ", i); REP(j,g[i].size()) printf("%d ", g[i][j]); puts(""); }

    bool tmp = true;

    REP(i,h) memo[g[i].size()] = true;
    REP(i,h) if(!memo[i]) tmp = false;

    if(!tmp){
      REP(i,h) if(g[i].size() == h - 1){
	// for each start point
	vector<vector<int> > gg(2 + 2 * h);
	
	REP(j,h) if(j != i){
	  int r = 2 + j;
	  REP(k, g[j].size()) if(g[j][k] != i){
	    int l = 2 + h + g[j][k];
	    gg[l].push_back(r);
	    gg[r].push_back(l);
	  }
	}
	
	REP(k, g[i].size()){
	  int r = 2 + h + g[i][k];
	  gg[0].push_back(r); gg[1].push_back(r);
	  gg[r].push_back(0); gg[r].push_back(1);
	}
	
	int n = Matching(gg, 2 + h).solve();
	
	if(n == h - 1){
	  tmp = true;
	  break;
	}
      }
    }

    if(!tmp){
      ans = false;
      break;
    }

    // Repeat
    REP(i,max(h, w)) REP(j,i)
      swap(m[i][j], m[j][i]);
    swap(h, w);
  }

  puts(ans ? "YES" : "NO");

  return 0;
}