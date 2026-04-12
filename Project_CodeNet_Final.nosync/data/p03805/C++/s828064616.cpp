
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

void graph(int d){
  bool flag1 = false;
  if(d == N-1){
    // for(int i = 0; i < N; i++)
    //   cout << c[i] << " ";
    //   cout << endl;
    for(int i = 0; i < N-1; i++){
      if(m[c[i]][c[i+1]]==0)
        flag1 = true;
    }
    if(!flag1)
      ++ans;
  }
  else{
    
    for(int i = 2; i <= N; i++){
      bool flag2 = true;
      for(int j = 1; j <= d; j++){
        if(c[j]==i)
          flag2 = false;
      }
      if(flag2){
        c[d+1] = i;
        graph(d+1);
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

  graph(0);

  cout <<ans << endl;
  return 0;
}

