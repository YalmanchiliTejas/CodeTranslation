#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int r,c,m;
  string grid[50];
  int cost[50][50],on[50][50],off[50][50];
  bool use[50][50];
  vector<pair<int,int> > route[50][50];
  vector<pair<int,int> > task;
  int y,x,prvy,prvx;

  cin >> r >> c >> m;

  for(int i=0;i<r;i++)cin >> grid[i];

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)cin >> cost[i][j];
  }
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)cin >> on[i][j];
  }
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)cin >> off[i][j];
  }

  cin >> prvy >> prvx;
  task.push_back(make_pair(prvy,prvx));
  for(int i=1;i<m;i++){
    cin >> y >> x;

    for(int j=0;j<r;j++){
      for(int k=0;k<c;k++){
	use[j][k] = false;
	route[j][k].clear();
      }
    }

    queue<pair<int,int> > q;
    q.push(make_pair(prvy,prvx));
    use[prvy][prvx] = true;

    while(q.size()){
      pair<int,int> tmp;
      tmp = q.front();
      q.pop();
      int f = tmp.first,s = tmp.second;
      if(f==y && s==x)break;
      int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};

      for(int k=0;k<4;k++){
	int sy = f+dy[k], sx = s+dx[k];

	if(sy<0 || sx<0 || sy>=r || sx>=c)continue;
	if(use[sy][sx] || grid[sy][sx]=='#')continue;

	for(int l=0;l<(int)route[f][s].size();l++){
	  route[sy][sx].push_back(route[f][s][l]);
	}
	route[sy][sx].push_back(make_pair(sy,sx));
	use[sy][sx] = true;
	q.push(make_pair(sy,sx));
      }
    }
    for(int j=0;j<(int)route[y][x].size();j++)task.push_back(route[y][x][j]);
   
    prvy = y;prvx = x;
  }

  //for(int i=0;i<(int)task.size();i++)cout << task[i].first << " " << task[i].second << endl;

  vector<int> visit[50][50];
  for(int k=0;k<(int)task.size();k++)visit[task[k].first][task[k].second].push_back(k);

  int res = 0;

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(visit[i][j].size())res += on[i][j] + off[i][j];

      for(int k=0;k<(int)visit[i][j].size();k++){
	if(k+1<(int)visit[i][j].size()){
	  if( (visit[i][j][k+1] - visit[i][j][k])*cost[i][j] < on[i][j] + off[i][j]){
	    res += (visit[i][j][k+1] - visit[i][j][k])*cost[i][j];
	  }else{
	    res += on[i][j] + off[i][j];
	  }
	}
      }
    }
  }
  cout << res << endl;
}