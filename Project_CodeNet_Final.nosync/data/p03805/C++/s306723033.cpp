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


int N,M;
bool tree[8][8];


int count(int x, int res){
  if(!res) return 1;
  int cnt = 0;

  rep(i, N){
    if((res>>i & 1) && tree[x][i]){
      cnt += count(i, res-(1<<i));
    }
  }

  return cnt;
}



int main() {
  cin >> N >> M;
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--;b--;
    tree[a][b] = true;
    tree[b][a] = true;
  }

  int ans = 0;
  int res = (1<<N) - 2;
  // set<int> s;
  // rep(i,N-1) s.insert(i+1);

  ans = count(0,res);

  cout << ans << endl;



}
