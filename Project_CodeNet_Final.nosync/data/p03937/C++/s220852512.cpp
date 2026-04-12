#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
#define Uniq(v) v.erase(unique(All(v)),v.end())
typedef pair<int, int> Pii; 
typedef pair<int, Pii> Pip;
typedef pair<string, int> Psi;
const int INF = (1<<30);
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};

int main()
{
  int H, W;
  char A[9][9];
  bool arrive = false;
  int visited_cells = 0;

  cin >> H >> W;
  Rep(i, H) Rep(j, W) {
    cin >> A[i][j];
    if( A[i][j] == '#' ) visited_cells++;
  }
  
  queue<Pip> q;
  bool used[9][9] = {{0}};
  q.push( Pip(1, Pii(0, 0)) );
  while( !q.empty() ) {
    Pip p = q.front(); q.pop();
    int now_cells = p.fr, y = p.sc.fr, x = p.sc.sc;
    if( y == H-1 && x == W-1 && now_cells == visited_cells ) {
      arrive = true;
      break;
    }
    if( used[y][x] ) continue;
    used[y][x] = true;
    if( y+1 < H && A[y+1][x] == '#' ) {
      q.push( Pip(now_cells+1, Pii(y+1, x)) );
    }
    if( x+1 < W && A[y][x+1] == '#' ) {
      q.push( Pip(now_cells+1, Pii(y, x+1)) );
    }
  }

  if( arrive ) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
