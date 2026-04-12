#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600

int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int> > vec(h, vector<int>(w));
  rep(i,h) rep(j,w) cin>>vec[i][j];
  vector<vector<int> > v(h+w, vector<int>(max(h,w),-1));
  rep(k,h+w-1){
    int i=k,j=0;
    if(k>=h){ i=h-1; j=k-h+1;}
    int d=j;
    while(i>=0 && j<w){
      v[k][d] = vec[i][j];
      i--;j++;d++;
    }
  }

  int d=max(h,w);
  vector<vector<int>> prev(d,vector<int>(d,-1));
  prev[0][0]=0;
  rep(k, h+w-1){
    vector<vector<int>> nxt(d,vector<int>(d,-1));
    rep(j,d)rep(i,j+1)if(prev[i][j]>=0){
      auto c = [&](int a,int b){
        if(v[k][a]<0 || v[k][b]<0) return -INF;
        else if(a==b) return v[k][a];
        else return v[k][a]+v[k][b];
      };
      nxt[i][j] = max(nxt[i][j], prev[i][j]+c(i,j));
      if(i+1<=j) nxt[i+1][j] = max(nxt[i+1][j], prev[i][j]+c(i+1,j));
      if(j+1<d){
        nxt[i+1][j+1] = max(nxt[i+1][j+1], prev[i][j]+c(i+1,j+1));
        nxt[i][j+1] = max(nxt[i][j+1], prev[i][j]+c(i,j+1));
      }
    }
    swap(prev,nxt);
  }

  cout << prev[d-1][d-1] << endl;
  return 0;
}
