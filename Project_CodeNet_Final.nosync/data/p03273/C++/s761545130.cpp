#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<vector>
typedef long long int ll;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR_IN(i, a, b) for(int i = (a); i < (b); i++)
#define BETWEEN(x, a, b) ((x) >= (a) && (x) <= (b))
#define BIT(b, i) (((b) >> (i)) & 1)
#define LOG_F 1
#define LOG(...) if(LOG_F) fprintf(stderr, __VA_ARGS__)

using namespace std;

ll pow(int x, int n){
  return n == 0 ? 1 : x * pow(x, n - 1);
}


/*
h w
a11 .. a1w
..
ah1 .. ahw
 */

int h,w;
char a[100][100];

int main(){
  cin>>h>>w;
  REP(i,h){
    REP(j,w){
      cin>>a[i][j];
    }
  }

  set<int> white_row, white_col;
  
  REP(i,h){
    bool all_white = true;
    REP(j,w){
      all_white = all_white && (a[i][j] == '.');
    }
    if(all_white) white_row.insert(i);
  }

  REP(j,w){
    bool all_white = true;
    REP(i,h){
      all_white = all_white && (a[i][j] == '.');
    }
    if(all_white) white_col.insert(j);
  }

  REP(i,h){
    REP(j,w){
      if(white_row.count(i) == 0 && white_col.count(j) == 0)
        cout<< a[i][j];
    }
    cout<<endl;
  }
  

  return 0;
}
