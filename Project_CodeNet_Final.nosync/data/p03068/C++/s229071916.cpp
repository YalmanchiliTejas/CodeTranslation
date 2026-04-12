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
  int n,k;
  string s;
  vector<char> ans;
  cin>>n>>s>>k;
  char c=s[k-1];
  for(int i=0;i<n;i++){
    if(s[i]==c){ans.push_back(c);}
    else ans.push_back('*');
  }
  for(int i=0;i<n;i++){
    cout<<ans[i];
  }
  return 0;
}