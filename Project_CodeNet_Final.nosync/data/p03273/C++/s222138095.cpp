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
const int mod=1000000007;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int gcd(int a, int b){
  if (a%b==0){
    return(b);
  }
  else{
    return(gcd(b,a%b));
  }
}


// ll memo[2020][2020];
// int pascal_triangle(){
//   for(int i = 0; i < 2020; i++){
//     for(int j = 0; j < i+1; j++){
//       if(j == 0 || j == i) memo[i][j] = 1;
//       else{
// 	memo[i][j] = (memo[i-1][j-1]+memo[i-1][j]);
//       }
//     }
//   }
//   return 0;
// }


int factrial(int n){
  if(n == 0) return 1;
  return n*factrial(n-1);
}

// int comb(int n, int k){
//   return fact(n) / (fact(n-k)*fact(k));
// }


char grid[110][110];
bool h[110];
bool w[110];

int main(){
  int H,W;
  cin >> H >> W;
  rep(i,H){
    bool f = true;
    rep(j,W){
      cin >> grid[i][j]; 
      if(grid[i][j] == '#') f = false;
    }
    if(f) w[i] = true;
  }

  rep(j,W){
    bool f = true;
    rep(i,H){
      if(grid[i][j] == '#') f = false;
    }
    if(f) h[j] = true;
  }
  rep(i,H){
    if(w[i] == true) continue;
    rep(j,W){
      if(h[j] == true) continue;
      else cout << grid[i][j];
    }
    cout << endl;
  }
  
  
}

