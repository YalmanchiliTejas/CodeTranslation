#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <stack>
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef pair<int,int> pint;
typedef vector<pint> vping;

#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};


int N,M, cnt;
bool tree[8][8];
bool vst[8];


void dfs(int v, int num){
  if(num == N){
    cnt++;return;
  }
  rep(i,N){
    if(tree[v][i] && !vst[i]){
      vst[i] = true;
      dfs(i, num+1);
      vst[i] = false;
    }
  }
}



int main() {
  rep(i,8) vst[i]=false;

  cin >> N >> M;
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--;b--;
    tree[a][b] = true;
    tree[b][a] = true;
  }

  vst[0] = true;
  dfs(0,1);


  cout << cnt << endl;



}
