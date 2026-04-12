




#include <bits/stdc++.h>
using namespace std;
pair<long long,long long> dp[3001][3001];
/*int rec(int i,int j,vector<int> &v,int cnt){
   
    if(i>j)
    return 0;
    int a=0,b=0;
    if(cnt%2==0){
    a=max((v[i]+rec(i+1,j,v,cnt++)),v[j]+rec(i,j-1,v,cnt++));
    }
    else{
    b=max((v[i]+rec(i+1,j,v,cnt++)),v[j]+rec(i,j-1,v,cnt++));
    }
    cout<<a<<" "<<b<<endl;
    ans=min(ans,a-b);
    return ans;
}
*/

int main() {
    int n;
    cin>>n;
    vector<long long> v;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }


  for(int i=0;i<n;i++){
      dp[i][i].first=v[i];
      dp[i][i].second=0;
  }
  int k=n-1;
  for(int j=1;j<n;j++){
      int l=j;
     for(int i=0;i<k;i++){

         long long a=v[l]+dp[i][l-1].second;
         long long b=v[i]+dp[i+1][l].second;
        
         if(a>b){
             dp[i][l].first=v[l]+dp[i][l-1].second;
             dp[i][l].second=dp[i][l-1].first;
         }
         else{
             dp[i][l].first=v[i]+dp[i+1][l].second;
             dp[i][l].second=dp[i+1][l].first;
         }
         l++;
     }
     k--;
  }
  long long ans=dp[0][n-1].first-dp[0][n-1].second;
  cout<<ans<<endl;
}
