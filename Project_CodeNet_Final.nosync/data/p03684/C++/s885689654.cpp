#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
const int inf = 1000000001;
const ll INF = 1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

#define N 100010
int n;
//i‚ÆM[i].second‚ðM[i].first‚Å‚Â‚È‚®
vector< vector<pii> > M(N, vector<pii>());
vector<bool> used(N, false);
vector< pair<pii, int> > r(N);
vi mincost(N, inf);

bool cmp1(pair<pii, int> a, pair<pii, int> b) {
  if (a.first.second < b.first.second) {
    return true;
  }
  else if (a.first.second > b.first.second) {
    return false;
  }
  else {
    if (a.first.first < b.first.first) {
      return true;
    }
    else if (a.first.first > b.first.first) {
      return false;
    }
    else {
      if (a.second < b.second) {
	return true;
      }
      else {
	return false;
      }
    }
  }
}


void init() {
  cin >> n;
  r.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i].first.first >> r[i].first.second;
    r[i].first.first--;
    r[i].first.second--;
    r[i].second = i;
  }
  sort(r.begin(), r.end());
  for (int i = 0; i < n - 1; i++) {
    int x1 = r[i].first.first, y1 = r[i].first.second;
    int x2 = r[i + 1].first.first, y2 = r[i + 1].first.second;
    int r1 = r[i].second, r2 = r[i + 1].second;
    M[r1].push_back(make_pair(min(abs(x2 - x1), abs(y2 - y1)), r2));
    M[r2].push_back(make_pair(min(abs(x2 - x1), abs(y2 - y1)), r1));
  }
  sort(r.begin(), r.end(), cmp1);
  for (int i = 0; i < n - 1; i++) {
    int x1 = r[i].first.first, y1 = r[i].first.second;
    int x2 = r[i + 1].first.first, y2 = r[i + 1].first.second;
    int r1 = r[i].second, r2 = r[i + 1].second;
    M[r1].push_back(make_pair(min(abs(x2 - x1), abs(y2 - y1)), r2));
    M[r2].push_back(make_pair(min(abs(x2 - x1), abs(y2 - y1)), r1));
  }
}



void prim(int s) {
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  int used_cnt = 0;
  mincost[s] = 0;
  pq.push(make_pair(0, s));
  int i;
  while (used_cnt < n) {
    int u;
    pii f;
    while (true) {
      f = pq.top();
      pq.pop();
      u = f.second;
      if (!used[u]) {
	break;
      }
    }
    mincost[u] = f.first;
    for (i = 0; i < M[u].size(); i++) {
      int v = M[u][i].second;
      int c = M[u][i].first;
      pq.push(make_pair(c, v));
    }
    used[u] = true;
    used_cnt++;
  }
}

void ans() {
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += mincost[i];
  }
  cout << sum << endl;
}

void solve() {
  init();
  prim(0);
  ans();
  return;
}

int main() {
  solve();
}

/*
3
1 5
3 9
7 8

6
8 3
4 9
12 19
18 1
13 5
7 6
*/
