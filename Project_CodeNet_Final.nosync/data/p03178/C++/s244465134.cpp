#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
ll p=1e9 + 7;
ll solve(){
  int d;
  string k;
  cin>>k>>d;
  ll dp[k.size()+1][d];
  ll powerof10[k.size()+1];
  powerof10[0]=1%d;
  for(int i=1;i<=k.size();i++){
      powerof10[i]=powerof10[i-1]*10;
      powerof10[i]%=d;
  }
  for(int i=0;i<=k.size();i++){
      for(int j=0;j<d;j++){
          dp[i][j]=0;
      }
  }
  dp[0][0]=1;
  ll maximal=0;
  for(int i=0;i<k.size();i++){
    if(i!=0){
        for(int j=0;j<d;j++){
            for(int k=0;k<10;k++){
                dp[i+1][(j+k)%d]+=dp[i][j];
            }
        }
    }
    for(int j=0;j<k[i]-'0';j++){
        dp[i+1][(maximal+j)%d]++;
    }
    maximal+=(k[i]-'0');
    maximal%=d;
    for(int j=0;j<d;j++){
        dp[i+1][j]%=p;
    }
  }
  if(maximal%d){
      dp[k.size()][0]--;
  }
  return (dp[k.size()][0]+p)%p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}