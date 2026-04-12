#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

const long long INF = 100000000000000000;



class Data{
public:
  int point;
  bitset<9> explored;
  Data(){
    for (int i = 1; i <= 8;i++)
      explored.set(i);
  }
};

int main()
{
  int N;
  int M;
  cin >> N >> M;

  //辺を持つかどうか
  bool V[N + 1][N + 1];

  for (int i = 1; i <= N;i++){
    for (int j = 1; j <= N;j++){
      V[i][j] = false;
    }
  }

  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    V[a][b] = true;
    V[b][a] = true;
  }

  stack<Data> que;
  Data start;
  start.point = 1;
  start.explored.reset(1);
  que.push(start);

  int answer = 0;
  while (!que.empty())
  {
    Data now = que.top();
    que.pop();
    bool ans = true;
    //cout << now.explored << endl;
    for (int i = 1; i <= N; i++)
    {
      if (now.explored[i] == 1)
        ans = false;
    }
    if(ans)
      answer++;

    for (int i = 1; i <= N; i++)
    {
      if(V[now.point][i]==true && now.explored[i]==1){
        //cout << "y" << endl;
        Data next;
        next.point = i;
        next.explored = now.explored;
        next.explored.reset(i);
        que.push(next);
      }
    }
  }

  cout << answer << endl;
}
