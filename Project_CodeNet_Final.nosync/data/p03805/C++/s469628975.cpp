#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int N, M, ans = 0;
vector<int> a(30);
vector<int> b(30);
vector<int> c(9,1);
int m[9][9] = {0};
vector<int> homon(9,0);

void dfs(int cd){
  bool flag1 = true;
  for(int i = 1; i <= N;i++){
    if(homon[i] == 0)
      flag1 = false;
  }
  if(flag1){
    ++ans;
  }
  else{
    for(int i=2; i <=N; i++){
      if(m[cd][i] == 1 && homon[i] ==0){
        homon[i] = 1;
        dfs(i);
        homon[i] = 0;
      }
    }
  }

}

int main(){
  cin >> N >> M;

  for(int i = 0; i < M; i++){
    cin >> a[i] >> b[i];
    m[a[i]][b[i]]=1;
    m[b[i]][a[i]]=1;
  }

  homon[1] = 1;
  dfs(1);
  cout <<ans << endl;
  return 0;
}

