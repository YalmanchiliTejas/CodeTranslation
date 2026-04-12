#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#include <sstream>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort(ALL(x))
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main(){
  int h,w; cin>>h>>w;
  bool visited[h][w];
  vector<string> a(h);
  rep(i,h){
    cin>>a[i];
    rep(j,w) visited[i][j]=false;
  }
  queue<PII> q;
  q.push({0,0});

  while(!q.empty()){
    PII p = q.front(); q.pop();
    int i=p.first, j=p.second;
    visited[i][j]=true;
    bool c1=false, c2=false;
    if(i-1>-1){ //上方向は未訪問のマスがあるとまずい
      if(!visited[i-1][j]&&a[i-1][j]=='#') break;
    }
    if(j-1>-1){ //左方向は未訪問のマスがあるとまずい
      if(!visited[i][j-1]&&a[i][j-1]=='#') break;
    }
    if(i==h-1&&j==w-1) return cout<<"Possible"<<endl,0;
    if(i+1<h){ //下方向
      if(a[i+1][j]=='#') q.push({i+1,j}), c1=true;
    }
    if(j+1<w){ //右方向
      if(a[i][j+1]=='#') q.push({i,j+1}), c2=true;
    }
    // if(i-1>-1){ //上方向は未訪問のマスがあるとまずい
    //   if(!visited[i-1][j]&&a[i-1][j]=='#') break;
    // }
    // if(j-1>-1){ //左方向は未訪問のマスがあるとまずい
    //   if(!visited[i][j-1]&&a[i][j-1]=='#') break;
    // }
    if(c1==c2) break; //右か下どちらかのみ進むことができる
  }
  cout<<"Impossible"<<endl;

  return 0;
}
