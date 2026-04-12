#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
  int n,m;
  cin >> n >> m;

  bool g[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      g[i][j] = false;
    }
  }

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    g[a-1][b-1] = true;
    g[b-1][a-1] = true;
  }

  vector<int> order(n);
  for(int i=0;i<n;i++) order[i] = i;

  int cnt = 0;
  do{
    if(order[0] != 0) continue;

    for(int i=0;i<n-1;i++){
      int prev = order[i];
      int next = order[i+1];

      if(!g[prev][next]) break;

      if(i == n-2) cnt++;
    }


  }while(next_permutation(order.begin(),order.end()));

  cout << cnt << endl;

}