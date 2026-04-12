#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  int k;
  cin>>s>>k;
  vector<vector<int>>dp0(s.size(),vector<int>(s.size()+1));//i桁までにj個０以外がある数,nより小
  vector<vector<int>>dp1(s.size(),vector<int>(s.size()+1));//i桁までにj個０以外がある数、不明
  dp0[0][1]=s.at(0)-'0'-1;
  
  dp0[0][0]=1;

  dp1[0][1]=1;
  rep2(i,1,s.size()){
    rep(j,s.size()+1){
      if(j!=0){
        dp0[i][j]=9*(dp0[i-1][j-1])+dp0[i-1][j]+(max(0,s.at(i)-'0'-1))*dp1[i-1][j-1]+(min(1,s.at(i)-'0'))*dp1[i-1][j];
        if(s.at(i)!='0'){
          dp1[i][j]=dp1[i-1][j-1];
        }
        else{
          dp1[i][j]=dp1[i-1][j];
        }
      }
      else{
        dp0[i][j]=dp0[i-1][j];
        if(s.at(i)!='0'){
          dp1[i][j]=dp1[i-1][j];
        }
      }
    }
  }
  
  cout<<dp0[s.size()-1][k]+dp1[s.size()-1][k]<<endl;
  
}