#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N;
int x[100100], y[100100];
set<pii> g[100100];

int par[100100], sz[100100];

inline int find(int k) { return k==par[k] ? k : par[k]=find(par[k]); }
inline bool join(int a, int b) {
  a=find(a), b=find(b);
  if(a==b) return 0;
  if(sz[a]>sz[b]) swap(a,b);
  par[a]=b, sz[b]+=sz[a];
  return 1;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N;
  for(int i=0;i<N;i++) cin>>x[i]>>y[i];

  vector<pii> xp(N), yp(N);
  for(int i=0;i<N;i++) xp[i]={x[i],i}, yp[i]={y[i],i}, sz[i]=1,par[i]=i;
  sort(xp.begin(),xp.end());
  sort(yp.begin(),yp.end());

  min_queue<pair<int,pii>> q;
  for(int i=0;i<N-1;i++) {
    q.push({xp[i+1].fst-xp[i].fst, {xp[i].snd, xp[i+1].snd}});
  }
  for(int i=0;i<N-1;i++) {
    q.push({yp[i+1].fst-yp[i].fst, {yp[i].snd, yp[i+1].snd}});
  }
 
  ll res=0;
  while(!q.empty()) {
    auto pr=q.top();q.pop();
    int wt=pr.fst,a=pr.snd.fst,b=pr.snd.snd;
    if (!join(a,b)) continue;
    res += wt;
  }

  cout<<res<<endl;
  return 0;
}
