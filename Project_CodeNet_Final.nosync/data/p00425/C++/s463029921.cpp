#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

struct Dice{
  int top, front, side;
  int const static SUM = 7;
  void north(){
    int tmp = front;
    front = SUM - top;
    top = tmp;
  }
  void east(){
    int tmp = top;
    top = SUM - side;
    side = tmp;
  }
  void west(){
    int tmp = side;
    side = SUM - top;
    top = tmp;
  }
  void south(){
    int tmp = top;
    top = SUM - front;
    front = tmp;
  }
  void right(){
    int tmp = side;
    side = SUM - front;
    front = tmp;
  }
  void left(){
    int tmp = front;
    front = SUM - side;
    side = tmp;
  }
};

int main(){
  int n;
  while(scanf("%d", &n) && n){
    Dice d;
    d.top = 1; d.front = 2; d.side = 3;
    int res = 1;
    string op;
    //    printf("%d %d %d\n", d.top, d.front, d.side);
    rep(i, n){
      cin >> op;
      switch(op[0]){
      case 'N': d.north(); break;
      case 'E': d.east();  break;
      case 'W': d.west();  break;
      case 'S': d.south(); break;
      case 'R': d.right(); break;
      case 'L': d.left();  break;
      }
      res += d.top;
      //      printf("%d %d %d\n", d.top, d.front, d.side);
    }
    printf("%d\n", res);
  }
  return 0;
}