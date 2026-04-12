#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using Graph = vector<vector<int>>;

bool g[10][10]; 

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a][b] = g[b][a] = true;
  }

  vector<int> perm;
  for(int i = 0; i < n; ++i)perm.push_back(i);

  int count = 0;
  do{
    if(perm[0] != 0)break; 
    bool flg = true;
    for(int i = 0; i < n - 1; ++i){
      if(!g[perm[i]][perm[i + 1]])flg = false;
    }
    if(flg)++count;
  }while(next_permutation(perm.begin(), perm.end()));
  
  cout << count << endl;
}
