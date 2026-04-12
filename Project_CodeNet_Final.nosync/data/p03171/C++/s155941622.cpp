#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

const int MAX_N = 3010;
const int inf = 1LL << 60;

int a[MAX_N];

int N; int memo[MAX_N][MAX_N];

int dfs(int s, int t){ 
  
  if(memo[s][t] != -inf){ return memo[s][t];}
  //常にs<=tである約束に注意
  if( s == t ){ 
    if(N%2){return a[s];} //太郎でも二郎でも、これを返すしかもうない
    else{ return -a[s];}
  }
  
  bool side = false;
  if( (N-t+s)%2 ){ //太郎の番
    side = !side;
  }
  
  int res;
  
  if(side){ 
    res = max(dfs(s+1,t)+a[s],dfs(s,t-1)+a[t]);
  }
  else{
    res = min(dfs(s+1,t)-a[s],dfs(s,t-1)-a[t]);
  }
  
  return memo[s][t] = res;
}

  
  
signed main(void){ 
  
  cin >> N;
  
  for(int i = 0; i < N; i++){ cin >> a[i];} 
  
  for(int i = 0; i < MAX_N; i++){
    for(int j = 0; j < MAX_N; j++){ 
      memo[i][j] = -inf;
    }
  }
  
  cout << dfs(0,N-1) << endl;
  
  return 0;
}