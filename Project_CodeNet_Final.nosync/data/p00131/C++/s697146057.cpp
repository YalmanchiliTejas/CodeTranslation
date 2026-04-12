#include<iostream>
#include<vector>
using namespace std;
typedef vector<bool> VB;
typedef vector<VB> VVB;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool check(VVB& G)
{
  for(int i=1;i<=10;i++)
    for(int j=0;j<10;j++)
      if(G[i][j])
	return false;
  return true;
}

void next(VVB& G,int bit)
{
  for(int i=0;i<10;i++)
    G[0][i] = ((bit>>i)&1)?1:0; 
}

void execute(VVB&G,VVB& ans)
{
  ans.resize(11);
  for(int i=1;i<11;i++)
    {
      ans[i].resize(10);
      for(int j=0;j<10;j++)
	ans[i][j] = false;
    }

  for(int i=1;i<11;i++)
    {
      for(int j=0;j<10;j++)
	{
	  if(G[i-1][j])
	    {
	      G[i][j] = !G[i][j];
	      ans[i][j] = true;
	      for(int k=0;k<4;k++)
		{
		  int nx = j + dx[k];
		  int ny = i + dy[k];
		  if(!(0 <= nx && nx < 10 && 0 <= ny && ny <= 10))
		    continue;
		  G[ny][nx] = !G[ny][nx];
		}

	    }
	}
    }

}

int main()
{
  int n;
  cin >> n;
  while(n-- > 0)
    {
      VVB G;
      G.resize(11);
      G[0].resize(10);
      for(int i=1;i<=10;i++)
	{
	  G[i].resize(10);
	  for(int j=0;j<10;j++)
	    {
	      bool b;
	      cin >> b;
	      G[i][j] = b;
	    }
	}


      for(int m=0;m<=(1<<10)-1;m++)
	{
	  VVB pre_G = G;
	  VVB ans;
	  next(G,m);

	  execute(G,ans);

	  if(check(G))
	    {
	      for(int i=1;i<=10;i++)
		{
		  for(int j=0;j<10;j++)
		    {
		      cout << ans[i][j];
		      j == 9?cout << endl:cout << " ";
		    }
		}
	      break;
	    }
	  G = pre_G;
	}


    }
  return 0;
}