#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define INF 100000000
using namespace std;
const int mod = 1000000007;

vector<vector<int>> A(9,vector<int>(0));
int N;
int dfs(vector<int>& memo,int now,int numcnt){

  if(numcnt==N)return 1;
  int ans=0;
  for(int i=0; i<A[now].size(); i++){
    if(memo[A[now][i]]==0){
      memo[A[now][i]]=1;
      ans+=dfs(memo,A[now][i],numcnt+1);
      memo[A[now][i]]=0;
    }
  }
  return ans;
}
int main() {

  int M;
  cin>>N>>M;
  vector<int> memo(9);
  for(int i=0; i<M; i++){
    int a,b;
    cin>>a>>b;
    A[a].push_back(b);
    A[b].push_back(a);
  }
memo[1]=1;
cout<<dfs(memo,1,1)<<endl;
}
