#include<bits/stdc++.h>

using namespace std;

long long int check(vector<vector<long long int>> &dp,vector<long long int> &v,int start,int end){
  if(start>end) return 0;
  if(start == end) return v[start];
  
  if(dp[start][end] != -1) return dp[start][end];
  
  long long int left = v[start] + min(check(dp,v,start+2,end),check(dp,v,start+1,end-1));
  long long int right = v[end] + min(check(dp,v,start+1,end-1),check(dp,v,start,end-2));
  dp[start][end] = max(left,right);
  
  return dp[start][end];
}

int main(){
  long long int x;
  int n;
  cin >> n;
  vector<long long int> v;
  long long int summ=0;
  for(int i=0;i<n;i++){
    cin >> x;
    summ = summ + x;
    v.push_back(x);
  }
  vector<vector<long long int>> dp(n,vector<long long int>(n,-1));
  long long int result = check(dp,v,0,n-1);
  long long int result1 = summ-result;
  cout << result-result1 << endl;
}