#include <bits/stdc++.h>

using namespace std;
const int INF = numeric_limits<int>::max() / 2;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,k;cin>>n>>m>>k;
  std::vector<int> d(m+1);
  for(int i=0;i<m;i++){
      cin>>d[i];
      d[i]--;
  }
  VVI v(n+1,vector<int>(k+1));
  for(int i=0;i<n;i++)for(int j=0;j<k;j++){
    cin>>v[i][j];
    v[i][j]--;
  }
  std::vector<int> dp((1<<m)+1,INF);
  dp[(1<<m)-1]=0;
  queue<int> que;
  que.push((1<<m)-1);
  while(!que.empty()){
      for(int i=0;i<k;i++){
          int tmp=que.front(),next=0;
          for(int j=0;j<m;j++){
              if(tmp%2){
                  int mv=v[d[j]][i];
                  for(int p=0;p<m;p++){
                    if(d[p]==mv) next|=(1<<p);
                  }
              }
              tmp/=2;
          }
          //cout<<next<<endl;
          //cout<<"*"<<dp[next]<<endl;
          if(dp[next]==INF){
              que.push(next);
          }
          dp[next]=min(dp[next],dp[que.front()]+1);
      }
      que.pop();
  }
  cout<<dp[0]<<endl;
    return 0;
}