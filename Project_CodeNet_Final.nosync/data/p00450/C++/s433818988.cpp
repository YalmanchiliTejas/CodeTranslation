#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct Info{ int color, num;};
vector<Info> V;

void add(int col, bool odd){

  if(V.empty()){
    V.push_back((Info){col,1});
    return;
  }

  if(odd){
    //odd
    if(V.back().color == col) V.back().num++;
    else V.push_back((Info){col,1});
  }else{
    //even
    if(V.back().color == col) V.back().num++;
    else{
      int tmp = 1;
      while(!V.empty() && V.back().color != col){
	tmp += V.back().num;
	V.pop_back();
      }
      V.push_back((Info){col,tmp});
    }
  }
}

int main(){
  int n;
  while(scanf("%d",&n) && n){
    V.clear();
    for(int i = 0; i < n; i++){
      int in;
      scanf("%d",&in);
      add(in, !(i%2));
    }

    int ans = 0;
    for(int i = 0; i < (int)V.size(); i++)
      if(V[i].color == 0) ans += V[i].num;
    
    printf("%d\n",ans);
  }
  return 0;
}