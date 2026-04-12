#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000
/*
  3
1 0 4
  2
  5
*/
int dice[6][6] ={ // [top][front] -> right
  {-1, 2, 4, 1, 3,-1},
  { 3,-1, 0, 5,-1, 2},
  { 1, 5,-1,-1, 0, 4},
  { 4, 0,-1,-1, 5, 1},
  { 2,-1, 5, 0,-1, 3},
  {-1, 3, 1, 4, 2,-1}
};

/* ??\????????§?¨??????§???????????¨??????dx,dy,df
 ????????? y
 ???
 ???
 x

[k]  1
    ???
3 ???  ??? 2
    ???
    0
*/
const int dx[] = {1,-1,0,0}, dy[]={0,0,1,-1};
function<pair<int,int>(int,int)> df[] = { // return <top,front>
  [&](int t, int f){return mp(5-f, t);},
  [&](int t, int f){return mp(f, 5-t);},
  [&](int t, int f){return mp(5-dice[t][f], f);},
  [&](int t, int f){return mp(dice[t][f], f);},
  [&](int t, int f){return mp(t, dice[t][f]);},
  [&](int t, int f){return mp(t, 5-dice[t][f]);}
};

map<char,int> m = {
  {'N', 1},
  {'E', 2},
  {'W', 3},
  {'S', 0},
  {'R', 4},
  {'L', 5}
};

int main(){
  int n;
  while(cin>>n, n){
    int t = 0, f=1;
    int ans = 1;
    rep(i,n){
      string s;
      cin>>s;
      auto p = df[m[s[0]]](t,f);
      t = p.fi, f = p.se;
      ans += t+1;
    }
    cout << ans << endl;
  }

  return 0;
}