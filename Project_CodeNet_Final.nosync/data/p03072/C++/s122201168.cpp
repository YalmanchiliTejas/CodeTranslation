#include<iostream>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include <string>
#include <complex>
#include <functional>
#include <map>
#include <queue>
using namespace std;
using ll = long long;
//typedef pair<string,string> P;
//double dat[100][100];
//int dp[6][1010];//動的計画法
//int prime[100001];
//char str[1010][1010];
//typedef pair<ll,ll> A;
//vector<A> pc;
//int ABS(int a){return max(a,-a);}
int main() {
  int n;
  cin>>n;
  int h[n];
  for(int i=0;i<n;i++) cin>>h[i];
  int ans=1,m=h[0];
  for(int i=1;i<n;i++){
    if(h[i]>=m) ans++;
    m=max(m,h[i]);
  }
  cout<<ans;
  return 0;
}