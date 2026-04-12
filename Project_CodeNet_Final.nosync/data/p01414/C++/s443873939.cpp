#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
const double EPS=1e-6;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) a.rbegin(),a.rend()
#define FLL(a,b) memset((a),b,sizeof(a))
#define CLR(a) FLL(a,0)
#define declare(a,it) __typeof(a) it=(a)
#define FOR(it,a) for(declare(a.begin(),it);it!=a.end();++it)
#define FORR(it,a) for(declare(a.rbegin(),it);it!=a.rend();++it)
template<class T,class U> ostream& operator<< (ostream& o, const pair<T,U>& v){return o << "(" << v.F << ", " << v.S << ")";}
template<class T> ostream& operator<< (ostream& o, const vector<T>& v){o << "{";rep(i,SZ(v)) o << (i?", ":"") << v[i];return o << "}";}
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};
int s2i(string& a){stringstream ss(a);int r;ss>>r;return r;}
int geti(){int n;scanf("%d", &n);return n;}

char col[10][10];
int h[16],w[16];

vector<PI> ma;
int memo[1<<16];

int rec(int st){
  if(st == (1<<16)-1) return 0;
  if(memo[st] >= 0) return memo[st];
  //cout << st << endl;
  int& ret = memo[st] = 1000000;
  for(int i = 0; i < (int)ma.size(); ++i){
    int nst = (st & ~ma[i].first) | ma[i].second;
    ret = min(ret, rec(nst) + 1);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> h[i] >> w[i];
  }

  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      cin >> col[i][j];

  vector<pair<PI, PI> > box;
  for(int lx = -3; lx < 4; ++lx)
    for(int ty = -3; ty < 4; ++ty)
      for(int i = 0; i < n; ++i){
        if(lx+h[i]>0 && ty+w[i]>0)
          box.push_back({{max(lx,0),max(0,ty)},
                {min(lx+h[i],4),min(ty+w[i],4)}});
      }
  sort(box.begin(), box.end());
  box.erase(unique(box.begin(), box.end()), box.end());
  //cout << "h" << endl;
  
  for(int i = 0; i < (int)box.size(); ++i){
    int lx = box[i].first.first;
    int ly = box[i].first.second;
    int ux = box[i].second.first;
    int uy = box[i].second.second;
    int mask = 0;
    int rr = 0;
    int gg = 0;
    int bb = 0;
    for(int cx = lx; cx < ux; ++cx)
      for(int cy = ly; cy < uy; ++cy){
        mask |= 1 << (cx*4 + cy);
        (col[cx][cy]=='R'?rr:
         col[cx][cy]=='G'?gg:
         bb) |= 1 << (cx*4 + cy);
      }
    ma.push_back({mask,rr});
    ma.push_back({mask,gg});
    ma.push_back({mask,bb});
  }
  //cout << "h" << endl;

  queue<int> q;
  q.push(0);
  for(int cc = 0;!q.empty();++cc){
    queue<int> nq;
    while(!q.empty()){
      int cv = q.front();
      q.pop();
      if(memo[cv]) continue;
      memo[cv] = 1;
      if(cv == (1<<16) - 1){
        cout << cc << endl;
        return 0;
      }
      for(int i = 0; i < (int)ma.size(); ++i){
        int nv = (cv & ~ma[i].first) | ma[i].second;
        if(!memo[nv])
          nq.push(nv);
      }
    }
    q.swap(nq);
  }
  
  memset(memo, -1, sizeof(memo));  
  cout << rec(0) << endl;
  
  return 0;
}