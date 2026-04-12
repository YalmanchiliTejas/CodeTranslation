#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

const int HMAX=10,WMAX=10;
int H,W;
vector<vector<char> > maze(WMAX,vector<char> (HMAX));
vector<vector<bool> > checked(WMAX,vector<bool> (HMAX,false));


bool solve(){
  cin >> H >> W;
  rep(y,H)rep(x,W)cin >> maze[x][y];
  int s = 0;
  rep(y,H){
    rep(x,s) if(maze[x][y]=='#')return false;;
    if(maze[s][y] != '#')return false;;
    int ns = s;
    repp(x,s,W){
      if(x-ns>1 && maze[x][y] == '#') return false;
      if(maze[x][y] == '#' && maze[ns][y] == '#') ns = x;
    }
    s = ns;
  }
  if(s != W-1)return false;
  return true;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  cout << (solve()?"Possible":"Impossible") << endl;
  return 0;
}
