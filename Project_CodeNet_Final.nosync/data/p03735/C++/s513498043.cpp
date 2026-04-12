#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int main() {
  int N;cin >> N;
  vll x(N),y(N);
  int id_xmin=0,id_ymax=0;
  repeat(i,N){
    cin >> x[i] >> y[i];
    if(x[i] > y[i]) swap(x[i],y[i]);
    if(x[id_xmin]>x[i] || ( x[id_xmin]==x[i] && id_xmin==id_ymax )){
      id_xmin = i;
    }
    if(y[id_ymax]<y[i]){
      id_ymax = i;
    }
  }
  ll Rmax = y[id_ymax];
  ll Rmin = y[id_xmin];
  ll Bmax = x[id_ymax];
  ll Bmin = x[id_xmin];
  ll ans=0;
  repeat(i,N){
    if(i==id_xmin || i==id_ymax) continue;
    if(Rmin > y[i]){
      Rmin = y[i];
    }
    if(Bmax < x[i]){
      Bmax = x[i];
    }
  }
  ans = (Rmax-Rmin)*(Bmax-Bmin);
  if(id_xmin != id_ymax){
    Rmax = y[id_ymax];
    Rmin = x[id_xmin];
    Bmax = max(x[id_ymax],y[id_xmin]);
    Bmin = min(x[id_ymax],y[id_xmin]);
    repeat(i,N){
      if(i==id_xmin || i==id_ymax) continue;
      if((Bmin <= x[i] && x[i] <= Bmax)||(Bmin <= y[i] && y[i] <= Bmax)) continue;
      if(Bmax<x[i]) Bmax = x[i];
      else if(y[i]<Bmin) Bmin = y[i];
    }
    vint rest;
    repeat(i,N){
      if(i==id_xmin || i==id_ymax) continue;
      if((Bmin <= x[i] && x[i] <= Bmax)||(Bmin <= y[i] && y[i] <= Bmax)) continue;
      rest.push_back(i);
    }
    if(rest.size()){
      ll restxmin=INF,restymax=0;
      for(int r:rest){
        restxmin = min(restxmin,x[r]);
        restymax = max(restymax,y[r]);
      }
      if(Bmin-restxmin<restymax-Bmax) Bmin = restxmin;
      else Bmax = restymax;
    }
    ans = min(ans,(Rmax-Rmin)*(Bmax-Bmin));
  }
  cout << ans << endl;
  return 0;
}
