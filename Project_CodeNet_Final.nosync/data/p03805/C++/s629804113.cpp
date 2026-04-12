#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

#define ll long long
#define vecint vector<int>
#define listint list<int>

#define REP(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define print(a) cout << a << endl

int ans=0;
bool passed_vertex[8];

bool checkpass(bool passed_vertex[],int V){
  rep(i,V){
    if(passed_vertex[i]==false) return false;
  }
  return true;
}

void solve(int v,bool path[8][8],int V){
  rep(i,V){
    if(path[v][i]==true){
      bool array[8][8];
      rep(i,V){
        rep(j,V){
          array[i][j]=path[i][j];
        }
      }
      rep(j,V){
        path[j][i]=false;
      }
      passed_vertex[i]=true;
      solve(i,path,V);
      passed_vertex[i]=false;
      rep(j,V){
        path[j][i]=array[j][i];
      }
    }
  }
  if(checkpass(passed_vertex,V)) {
    ans++;
  }
  return;
}

int main(){
  int V,E;
  bool path[8][8];

  cin >> V >> E;
  rep(i,8){
    rep(j,8){
      path[i][j]=false;
    }
  }
  rep(i,E){
    int x,y;
    cin >> x >> y;
    path[x-1][y-1]=true;
    path[y-1][x-1]=true;
  }
  rep(i,8){
    passed_vertex[i]=false;
  }
  rep(i,V){
    path[i][0]=false;
  }
  passed_vertex[0]=true;
  solve(0,path,V);
  print(ans);
  return 0;
}
