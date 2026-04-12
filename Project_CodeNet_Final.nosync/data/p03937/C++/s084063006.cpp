#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
  int H,W;
  cin >> H >> W;

  vector<string> A(H);
  REP(i, H) cin >> A[i];
  
  
  int flag = 0;
  REP(i,H){
    REP(j,W){
      if(i==0&&j==0){
        if(A.at(0).at(1)=='#'&&A.at(1).at(0)=='#'){
          flag = 1;
        }
        continue;
      }
      if(i==H-1&&j==W-1){
        if(A.at(H-1).at(W-2)=='#'&&A.at(H-2).at(W-1)=='#'){
          flag = 1;
        }
        continue;
      }
      if(A.at(i).at(j)=='#'){
        //xは左上の#の数、yは右下の#の数
        int x = 0;
        int y = 0;
        REP(k,4){
          if(i+dy[k]<0||i+dy[k]>H-1||j+dx[k]<0||j+dx[k]>W-1) continue;
          if(A.at(i+dy[k]).at(j+dx[k])=='#'){
            if(k<2){
              y++;
            }else{
              x++;
            }
          }
        }
        if(x!=1||y!=1){
          flag=1;
        }
      }
    }
  }

  if(flag == 1){
    cout << "Impossible" << endl;
  }else{
    cout << "Possible" << endl;
  }
}