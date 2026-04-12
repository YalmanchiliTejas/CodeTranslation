#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FR first
#define SC second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, f, n) for(int i = (int)(f); i < (int)(n); i++)
#define each(a, b) for(auto& a : b)

typedef pair<int, string> P;

struct Chara
{
  string name;  
  int x;
  Chara(){}
  Chara(string name, int x):name(name), x(x){}
  bool operator < (const Chara& c) const {
    return x != c.x ? x > c.x : name < c.name;
  }
};

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int N, M, K, L;
set<string> favname;
vector<Chara> dic, fav, unf;

bool check(int k)
{
  if(unf.size() < K-k+1) return true;
  int l = 0;
  for(int i = 0; i < k; i++) {
    l += max(0LL, unf[K-k].x - fav[i].x + (fav[i].name > unf[K-k].name));
  }
  return l <= L;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  while(cin >> N >> M >> K >> L, N) {
    dic.clear();
    for(int i = 0; i < N; i++) {
      string name; int x;          
      cin >> name >> x;
      dic.push_back(Chara(name, x));
    }
    favname.clear();
    for(int i = 0; i < M; i++) {
      string name; cin >> name;
      favname.insert(name);
    }
    fav.clear();
    unf.clear();
    for(auto a : dic) {
      if(favname.find(a.name) != favname.end()) fav.push_back(a);
      else unf.push_back(a);
    }
    sort(all(fav));
    sort(all(unf));
    int lb = 0, ub = min(M, K) + 1;
    while(lb + 1 < ub) {
      int mb = (lb + ub) / 2;
      if(check(mb)) lb = mb;
      else ub = mb;
    }
    cout << lb << endl;
  }
  
  return 0;
}