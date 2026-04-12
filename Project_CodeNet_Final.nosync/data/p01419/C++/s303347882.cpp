#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<cassert>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)
#define all(v) (v).begin(),(v).end()
#define deb(a) cout << #a << " = " << a << endl
#define MAX 51
using namespace std;

struct P
{
  int x,y;
  P(int x=inf,int y=inf):x(x),y(y){}
  bool operator == (const P& a)const
  {
    return x == a.x && y == a.y;
  }
  bool operator < (const P& a)const
  {
    return (x!=a.x?x < a.x:y < a.y);
  }
};

struct Pox
{
  P p;
  vector<P> path;
  Pox(P p = P()):p(p){ path.clear(); }
};

int R,C,M;
char G[MAX][MAX];
int cost[3][MAX][MAX];// 0-> per unit of time, 1 -> turn on, 2 -> turn off
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dp[MAX][MAX];
int visited[MAX][MAX];

vector<P> task;
vector<P> route;

void findRoute()
{
  bool used[R][C];

  route.push_back(task[0]);

  rep(i,M-1)
    {
      rep(y,R)rep(x,C)used[y][x] = false;
      deque<Pox> deq;
      deq.push_back(Pox(task[i]));
      used[task[i].y][task[i].x] = true;
      P goal = task[i+1];
      
      bool found = false;
      //cout << "target : " << goal.x << "," << goal.y << endl; 
      while(!deq.empty())
	{
	  Pox pox = deq.front(); deq.pop_front();      
	  //cout << "pox = " << pox.p.x << "," << pox.p.y << endl;
	  if(pox.p == goal)
	    {
	   
	      rep(j,pox.path.size())
		{
		  //cout << "add " << pox.path[j].x << "," << pox.path[j].y << endl;
		  route.push_back(pox.path[j]);
		}
	      found = true;
	      break;
	    }

	  rep(j,4)
	    {
	      int nx = pox.p.x + dx[j];
	      int ny = pox.p.y + dy[j];
	      if(!( 0 <= nx && nx < C && 0 <= ny && ny < R ))continue;
	      if(G[ny][nx] == '#')continue;
	      if(!used[ny][nx])
		{
		  //cout << "goto " << nx << "," << ny << endl;
		  used[ny][nx] = true;
		  Pox npox = pox;
		  npox.path.push_back(P(nx,ny));	
		  npox.p = P(nx,ny);
		  deq.push_back(npox);
		}
	    }

	}
      assert(found);
    }
}

void compute()
{
  findRoute();
  int N = route.size();
  //rep(i,N)
    //cout << "route["<<i<<"] = (" <<route[i].x << "," << route[i].y << ")\n";
  
  rep(y,R)rep(x,C)dp[y][x] = visited[y][x] = inf;
  

  rep(i,N)
    {  
      int x = route[i].x;
      int y = route[i].y; 
            
      if(visited[y][x] == inf)
	{
	  dp[y][x] = cost[1][y][x] + cost[2][y][x];
	}
      else
	{
	  dp[y][x] = min(dp[y][x]+cost[1][y][x]+cost[2][y][x],
			 dp[y][x]+(i-visited[y][x])*cost[0][y][x]);
	}

      visited[y][x] = i;
    }
  sort(all(route));
  route.erase(unique(all(route)),route.end());
  int ans = 0;
  rep(i,route.size())ans += dp[route[i].y][route[i].x];
  cout << ans <<endl;
}

int main()
{
  cin >> R >> C >> M;
  task.resize(M);
  rep(i,R)rep(j,C)cin >> G[i][j];
  rep(i,3)rep(j,R)rep(k,C)cin >> cost[i][j][k];
  rep(i,M)cin >> task[i].y >> task[i].x;
  compute();

  return 0;
}