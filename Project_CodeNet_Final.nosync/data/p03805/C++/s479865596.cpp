#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int edge[10][10]={};

int bitdp(int N,int n,int mask,int last){
  if(n==N){
    return 1;
  }
  int i;
  int ans = 0;
  for(i=0;i<N;i++){
    if(mask & 1<<i && ( edge[last][i] || edge[i][last] )){
      ans += bitdp(N,n+1,mask - (1<<i),i);
    }
  }
  return ans;
}


int main()
{
  int n,m;
  cin >> n >> m;
  int i;
  for(i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    edge[a-1][b-1]=1;
    edge[a-1][b-1]=1;
  }

  int ans = bitdp(n,1,(1<<n) - 1 - 1,0);
  cout << ans << endl;
  return 0;
}
