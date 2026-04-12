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
#include <bitset>
#include <iomanip>
#include <cassert>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A,B;cin>>A>>B;
  vector<vll> d(A,vll(B));
  repeat(i,A){
    repeat(j,B){
      cin>>d[i][j];
    }
  }
  vector<vll> f(110,vll(110,0));
  repeat(a,101){
    repeat(b,101){
      repeat(x,A){
        repeat(y,B){
          f[a][b]=max(f[a][b],d[x][y]-a*(x+1)-b*(y+1));
        }
      }
    }
  }
  vector<vll> D(A,vll(B,INF));
  bool isok=true;
  repeat(x,A){
    repeat(y,B){
      repeat(a,101){
        repeat(b,101){
          D[x][y]=min(D[x][y],a*(x+1)+b*(y+1)+f[a][b]);
        }
      }
      isok &= D[x][y]==d[x][y];
    }
  }
  if(!isok){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  cout << 202 << " " << 200+101*101 << endl;
  repeat(i,100){
    cout << i+1 << " " << i+2 << " X" << endl;
  }
  repeat(i,100){
    cout << i+102 << " " << i+103 << " Y" << endl;
  }
  repeat(i,101){
    repeat(j,101){
      cout << i+1 << " " << 202-j << " "<< f[i][j] << endl;
    }
  }
  cout << "1 202" << endl;
  return 0;
}
