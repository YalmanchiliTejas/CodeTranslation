#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define RREP(i, N) for (int i =(int)N-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;



int main(){
  int h,w;
  cin>>h>>w;
  char t[h][w];
  vector<int> hv;
  vector<int>::iterator hitr;
  vector<int>::iterator witr;
  vector<int> wv;
  REP(i,h){
    REP(j,w){
      cin>>t[i][j];
    }
  }
  REP(i,h){
    REP(j,w){
      if(t[i][j]=='#')break;
      if(j==w-1){
        hv.push_back(i);
      }
    }
  }
  REP(j,w){
    REP(i,h){
      if(t[i][j]=='#')break;
      if(i==h-1){
        wv.push_back(j);
      }
    }
  }
  if(hv.empty()==0){
  hitr=hv.begin();
  }
  if(wv.empty()==0){
  witr=wv.begin();
  }
  REP(i,h){
    if(!hv.empty()&&i==*hitr){
      hitr++;
      continue;
    }
    REP(j,w){
      if(!wv.empty()&&j==*witr){
        witr++;
        continue;
      }else{
        cout<<t[i][j];
      }

    }
    witr=wv.begin();
    cout<<endl;
  }
}
