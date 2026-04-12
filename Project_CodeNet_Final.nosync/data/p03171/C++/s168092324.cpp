#define rep(i,n) for (int i=0;i<n;i++)
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long INF = 1LL<<60;

int main(){
  
  int N;
  cin >> N;
  
  vector<int> a(N);
  rep(i,N)
    cin >> a.at(i);
  
  vector<vector<long>> dp(N+1,vector<long>(N+1));
  
  rep(i,N)
    dp.at(i).at(i)=0;
  
  for(int len=1;len<=N;len++){
    for(int i=0;len+i<=N;i++){
      int j=len+i;
      
      if((N-len)%2==0){
        dp.at(i).at(j)=max(dp.at(i).at(j-1)+a.at(j-1),dp.at(i+1).at(j)+a.at(i));
      }else{
        dp.at(i).at(j)=min(dp.at(i).at(j-1)-a.at(j-1),dp.at(i+1).at(j)-a.at(i));
      }
      
      
     
      
      
    }
    
    
  }
  
  
   cout << dp.at(0).at(N) << endl;
 
  
}