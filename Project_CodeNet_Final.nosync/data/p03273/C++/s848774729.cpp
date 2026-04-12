#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
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




char field[110][110];
int H,W;

int main(){

  int H,W;
  vector<bool> h(H,false);
  vector<bool> w(W,false);    
  cin >> H >> W;
  rep(i,H){
    rep(j,W){
      cin >> field[i][j];
      if(field[i][j] == '#'){
	h[i] = true;
	w[j] = true;
      }
    }
  }
  rep(i,H){
    if(h[i]){
      rep(j,W){
	if(w[j]){
	  cout << field[i][j];
	}
      }
      cout << endl;
    }
  }
  
}
