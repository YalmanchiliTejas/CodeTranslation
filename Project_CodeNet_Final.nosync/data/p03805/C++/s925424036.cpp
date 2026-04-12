#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include<iomanip>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

using namespace std;
int res=0;
int n;
int m;
int edge[9][9];

void dfs(int no,int bit)
{
  if(bit==(1<<n)-1){res++;return;}
  repi(i,1,n+1)
  {
    if(edge[no][i]==1 && (!(bit & (1<<(i-1)))))
    {
      dfs(i,bit+(1<<(i-1)));
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  //cout<<setprecision(10);
  cin>>n>>m;
  rep(i,m)
  {
    int a,b;
    cin>>a>>b;
    edge[a][b]=1;
    edge[b][a]=1;
  }
  dfs(1,1);
  cout<<res<<endl;



  return 0;

}
