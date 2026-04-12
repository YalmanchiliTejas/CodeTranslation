#include<bits/stdc++.h>
using namespace std;


typedef long long lli;
typedef unsigned long ul;
typedef pair<lli,lli> pll;
typedef vector<lli> vl;
#define rep(i,n) for(lli i=0; i<(n); ++i)
#define reps(i,n) for(lli i=1; i<n; ++i)
#define rrep(i,x) for(lli i=((n)-1); i>=0; --i)
#define rreps(i,x) for(lli i=((n)); i>0; --i)
#define REP(i,n) for(lli i=0; i<n; ++i)
#define REPS(i,n) for(lli i=1; i<n; ++i)
#define RREP(i,x) for(lli i=((n)-1); i>=0; --i)
#define RREPS(i,x) for(lli i=((n)); i>0; --i)
#define FOR(i,a,b) for (lli i=(a);i<(b);i++)
#define INF LONG_MAX/3
#define PB push_back
#define pb push_back
#define FT first
#define SD second
#define y0 y348
#define y1 y348
#define next asdnext
#define prev asdprev
#define all(a) (a).begin(),(a).end()
#define eps pow(10,-7)
#define SZ(x) ((int)(x).size())
#define fill(x,y) memset(x,y,sizeof(x))

lli gcd(lli a,lli b){return b?gcd(b,a%b):a;}
lli dx[4]={1,0,-1,0};
lli dy[4]={0,1,0,-1};

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
  lli H,W;
  string str[100];
  bool f=true,ff;

  cin >>H>>W;
  rep(i,H)
    cin>>str[i];


  while(f){
    f=false;
    rep(i,H){
      if(str[i].find('#')==-1){
	FOR(j,i,H-1)
	  str[j]=str[j+1];
	H--;
	f=true;
      }
    }
    rep(i,W){
      ff=false;
      rep(j,H){
	if(str[j][i]=='#')ff=true;
      }

      if(!ff){
	f=true;
	rep(j,H)
	  str[j].erase(str[j].begin()+i);
	W--;
      }
    } 
  }
  
  rep(i,H)
    cout << str[i] << endl;
  return 0;
}
