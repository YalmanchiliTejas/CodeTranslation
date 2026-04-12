#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

VS decomp(string s){
  int h = 1, w = 0;
  int n = SZ(s);
  for(int i=0;i<n;++i) if(s[i] == '/') ++h;
  for(int i=0;i<n&&s[i]!='/';++i){
	if(s[i] == 'b') ++w;
	else w += s[i] - '0';
  }

  VS res(h, string(w, '.'));
  int y = 0, x = 0;
  for(int i=0;i<n;++i){
	if(s[i] == '/'){
	  ++y;
	  x = 0;
	}
	else if(s[i] == 'b'){
	  res[y][x++] = 'b';
	}
	else{
	  x += s[i] - '0';
	}
  }
  return res;
}
string comp(VS& vs){
  int h = SZ(vs);
  int w = SZ(vs[0]);
  string res;
  for(int y=0;y<h;++y){
	int acc = 0;
	for(int x=0;x<w;++x){
	  if(vs[y][x] == '.') ++acc;
	  else{
		if(acc) res += to_string(acc);
		res += "b";
		acc = 0;
	  }
	}
	if(acc)
	  res += to_string(acc);
	if(y < h-1) res += "/";
  }
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S;
  while(cin>>S,S!="#"){
	int sx, sy, tx, ty;
	cin >> sy >> sx >> ty >> tx;
	--sy;
	--sx;
	--ty;
	--tx;
	VS vs = decomp(S);
	vs[sy][sx] = '.';
	vs[ty][tx] = 'b';
	cout << comp(vs) << endl;
  }

  return 0;
}