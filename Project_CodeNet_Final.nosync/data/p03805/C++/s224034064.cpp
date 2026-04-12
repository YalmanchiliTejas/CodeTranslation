#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;

#define MAX_N 100
#define MAX_M 100
#define INF   10000

vector<int> G[MAX_N];

int main() {

  // ---------------------
  // Input
  
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

 
  // input
  int N, M;
  cin >> N >> M;
  
  for(int i = 0; i < M; i++) {

    int a, b;
    cin >> a >> b;
    
    G[a].push_back(b);
    G[b].push_back(a);
    
  }
  
  // ---------------------
  // 

  int array[N-1];
  
  for (int i = 0; i < N-1; i++) {
    array[i] = i + 2;
  }

  int num_path = 0;
  
  do{

    bool flag = false;

    for (int j = 0; j < G[1].size(); j++) {
      if (G[1][j] == array[0]) flag = true;
    }
    if (!flag) continue;
    
    for (int i = 0; i < N-2; i++) {
      int node = array[i];

      flag = false;
      for (int j = 0; j < G[node].size(); j++) {
	if (G[node][j] == array[i+1]) flag = true;
      }
      if (!flag) break;
    }

    if (flag) num_path++;
    
  }while(next_permutation(array, array + N - 1));


  cout << num_path << endl;

  return 0;
  
}
