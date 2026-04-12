#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}
int main() {
  string N;
  int k;
  cin >> N >> k;
  int l=N.size();
  vector<int> v(l);
  rep(i,l)
    v[i]=(N[i]-'0');
  int dp[101][2][5]={};
  // Fill(dp,0);
  dp[0][0][0]=1;
  rep(i,l)
    rep(s,2){
      int y=(s?9:v[i])+1;
      rep(j,k+1)
        rep(x,y){
          dp[i+1][s||x<v[i]][j+(x>0)]+=dp[i][s][j]; 
        }
    }
  cout<<dp[l][0][k]+dp[l][1][k];
}