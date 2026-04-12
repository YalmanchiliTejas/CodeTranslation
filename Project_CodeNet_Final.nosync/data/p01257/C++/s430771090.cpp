#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000;
using namespace std;
int n,m,a[11];
vector <int> coin;
int used[11];
void saiki(int sum,int k){
  for(int i=k;i<n;i++) {
    if(used[i]==1) continue;
    used[i]=1;
    coin.push_back(sum+a[i]);
    saiki(sum+a[i],i+1);
    used[i] = 0;
  }
}

int main() {
  while(1){
    cin >> n >> m;
    if(n==0&&m==0) break;
    coin.clear();
    for(int i=0;i<n;i++)cin >> a[i];
    saiki(0,0);

    int dp[100010]={};
    for(int i=1;i<=m;i++) dp[i] = INF;
    for(int i=0;i<coin.size();i++)
      for(int j=0;j<=m;j++)
	for(int k=1;j+coin[i]*k<=m && dp[j+coin[i]*k]>dp[j]+k;k++) dp[j+coin[i]*k] = dp[j]+k; 
    cout <<dp[m]<<endl;
  }
  return 0;
}