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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  while(cin>>N,N){
	stack<PII> st;
	FOR(i,1,N+1){
	  int c;
	  cin >> c;
	  if(i%2){
		if(!st.empty() && st.top().FF == c){
		  st.top().SS++;
		}
		else
		  st.push(MP(c,1));
	  }
	  else{
		int n = 1;
		while(!st.empty() && st.top().FF != c){
		  n += st.top().SS;
		  st.pop();
		}
		st.push(MP(c,n));
	  }
	}
	int ans = 0;
	while(!st.empty()){
	  if(st.top().FF == 0)
		ans += st.top().SS;
	  st.pop();
	}
	cout << ans << endl;
  }

  return 0;
}