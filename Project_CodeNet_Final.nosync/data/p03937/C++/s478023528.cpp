#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//　ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}

int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}



int main(){
  int H,W;
  cin >> H >> W;
  char c[H][W];
  rep(i,H){
    rep(j,W){
      cin >> c[i][j];
    }
  }
  
  int x = 0, y = 0;
  while(1){
    if(x<W && y<H){
      c[y][x] = '.';
      if(c[y][x+1] == '#' && x+1 < W) x++;
      else if(c[y+1][x] == '#'&& y+1 < H) y++;
      else break;
    }
    else break;
  }
  bool f = true;
  
  rep(i,H){
    rep(j,W){
      if(c[i][j] == '#') f=false;
    }
  }
  
  // rep(i,H){
  //   rep(j,W){
  //     cout << c[i][j];
  //   }
  //   cout << endl;
  // }  

  
  if(f) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}

