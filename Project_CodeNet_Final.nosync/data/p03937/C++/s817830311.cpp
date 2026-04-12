#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))
typedef long long Int;
char cnt[10][10];

void ok(){
  cout << "Possible" << endl;
  exit(0);
}

void ng(){
  cout <<  "Impossible" << endl;
  exit(0);
}

char c;
int main(){
  Int h, w;
  cin >> h >> w;
  for(int i = 1;i <= h;i++)
    for(int j = 1;j <= w;j++)
      cin >> cnt[i][j];
  for(int i = 1;i < h;i++){
    for(int j = 1;j < w;j++){
      
      if(cnt[i][j] == '#' && cnt[i+1][j] == '#' && cnt[i][j+1] == '#')ng();
      if(cnt[i][j] == '#' && cnt[i+1][j] == '.' && cnt[i][j+1] == '.')ng();
      if(cnt[i+1][j+1] == '#' && cnt[i+1][j] == '#' && cnt[i][j+1] == '#')ng();
    }
  }
  ok();
  return 0;
}
