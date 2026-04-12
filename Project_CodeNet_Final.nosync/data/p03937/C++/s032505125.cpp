#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

vector<vector<int>> dist;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};

int main(void)
{
  int height,width;
  cin >> height >> width;
  vector<string> field(height);
  for(int h = 0; h < height; h++) cin >> field[h];
  
  vector<vector<int>> dist(height,vector<int>(width,-1));
  dist[0][0]=0;
  
  vector<vector<int>> prev_x(height,vector<int>(width,-1));
  vector<vector<int>> prev_y(height,vector<int>(width,-1));

  queue<pair<int,int>> que;
  que.push(make_pair(0, 0));
  while(!que.empty())
  {
    const auto current=que.front();
    const int x=current.first;
    const int y=current.second;
    que.pop();

    for(int direction = 0; direction < 4; direction++)
	{
      int next_x = x + dx[direction];
      int next_y = y + dy[direction];
      if(next_x < 0 || next_x >= height || next_y < 0 || next_y >= width)
		  continue;
      if(field[next_x][next_y]=='.')
		  continue;
      if(dist[next_x][next_y] == -1)
	  {
        que.push(make_pair(next_x,next_y));
        dist[next_x][next_y] = dist[x][y] + 1;
		prev_x[next_x][next_y] = x;
		prev_y[next_x][next_y] = y;
      }
    }
  }
  /*int x = height - 1,y = width - 1;
  while(x != -1 && y != -1)
  {
    field[x][y] = dist[x][y] + '0';
    int px = prev_x[x][y];
    int py = prev_y[x][y];
    x = px,y = py;
  }
  for(int h=0;h<height;h++)
  {
    for(int w=0;w<width;w++)
	{
      cout << std::setw(3)<<field[h][w];
    }
     cout << endl;
   }
  cout << dist[height - 1][width - 1] <<endl;*/
  int maxi = -1;
  rep(i, height)
  {
	  rep(j, width)
	  {
		  if (dist[i][j] == -1) continue;
		  if (dist[i][j] > maxi)
			  maxi = dist[i][j];
		  else
		  {
			  cout << "Impossible" << endl;
			  return 0;
		  }
	  }
  }
  cout << "Possible" << endl;
  return 0;
}
