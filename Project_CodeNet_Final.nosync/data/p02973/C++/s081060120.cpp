#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  const int INF=2000000000;
  int n,i,dp[100010];
  scanf("%d\n",&n);
  vector<int> x(n);
  for(i=0;i<n;i++){
    scanf("%d\n",&x[i]);
  }
  reverse(x.begin(),x.end());
  for(i=0;i<=n;i++){
    dp[i]=INF;
  }
  for(i=0;i<n;i++){
    int min=-1,max=n,mid;
    while(abs(min-max)>1){
      mid=(min+max)/2;
      if(x[i]<dp[mid]){
        max=mid;
      }
      else{
        min=mid;
      }
    }
    dp[max]=x[i];
  }
  for(i=0;i<n;i++){
    if(dp[i]==INF){
      break;
    }
  }
  printf("%d\n",i);
  return 0;
}