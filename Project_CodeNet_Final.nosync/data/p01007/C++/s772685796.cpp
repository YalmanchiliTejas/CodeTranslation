#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int n,m;

vector<vector<bool> > rotate90(const vector<vector<bool> >& piece){
  vector<vector<bool> > ret;
  int h = piece[0].size(), w = piece.size();
  ret.resize(h);
  for(int i=0;i<h;i++)ret[i].resize(w);
  for(int y=0;y<ret.size();y++){
    for(int x=0;x<ret[0].size();x++){
      ret[y][x] = piece[ret[0].size()-1-x][y];
    }
  }
  return ret;
}


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool visited[100][100];

bool isValid(int x,int y) { return 0 <= x && x < n && 0 <= y && y < n; }

bool dfs(int x,int y,bool color,vector<vector<bool> > &vec){
  rep(i,4){
    int nx = x + dx[i], ny = y + dy[i];
    if( !isValid(nx,ny) ) continue;
    if( color == vec[ny][nx] && !visited[ny][nx] ) {
      vec[ny][nx] = !vec[ny][nx];
      visited[ny][nx] = true;
      dfs(nx,ny,color,vec);
    }
  }
}

int main(){

  cin >> n >> m;

  vector<vector<bool> > vec(n,vector<bool>(n,false));

  rep(i,n) rep(j,n) {
    int v;
    cin >> v;
    vec[i][j] = (v?true:false);
  }

  rep(i,m){
    int o;
    cin >> o;
    if( o == 0 ) {
      int r,c,size,angle;
      cin >> r >> c >> size >> angle;
      --r, --c;
      swap(r,c);
      vector<vector<bool> > temp(size,vector<bool>(size));
      rep(y,size) rep(x,size) temp[y][x] = vec[c+y][r+x];
      rep(_,angle/90) temp = rotate90(temp);
      rep(y,size) rep(x,size) vec[c+y][r+x] = temp[y][x];
    } else if( o == 1 ) {
      int r,c,size;
      cin >> r >> c >> size;
      --r, --c;
      swap(r,c);
      rep(y,size) rep(x,size) vec[c+y][r+x] = !vec[c+y][r+x];
    } else if( o == 2 ) {
      int r;
      cin >> r;
      --r;
      //rep(x,n-1) swap(vec[r][x],vec[r][x+1]);
      rep(x,n-1) {
	bool temp = vec[r][x];
	vec[r][x] = vec[r][x+1];
	vec[r][x+1] = temp;
      }
    } else if( o == 3 ) {
      int r;
      cin >> r;
      --r;
      //for(int x=n-1;x>0;x--) swap(vec[r][x],vec[r][x-1]);
      for(int x=n-1;x>0;x--) {
	bool temp = vec[r][x];
	vec[r][x] = vec[r][x-1];
	vec[r][x-1] = temp;
      }
    } else {
      memset(visited,false,sizeof(visited));
      int r,c;
      cin >> r >> c;
      --r, --c;
      bool color = vec[r][c];
      visited[r][c] = true;
      vec[r][c] = !color;
      dfs(c,r,color,vec);
    }
  }

  rep(i,n) {
    rep(j,n){
      if( j ) cout << ' ';
      cout << vec[i][j];
    } puts("");
  }

  return 0;
}