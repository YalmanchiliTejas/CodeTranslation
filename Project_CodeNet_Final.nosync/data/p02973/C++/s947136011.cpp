#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int inf=-1;
int upper(vector<int> const& dp,int const& key){
  int right=dp.size()-1;
  int left=0;int res;
  if(dp[right]>=key){
    res=right;
    goto FINE;
  }
  while(right-left>1){
    int mid=(right+left)/2;
    if(dp[mid]<key)right=mid;
    else left=mid;
  }
  res=right;
  FINE:
  return res;
}
void lis(int const& n,vector<int> const& c,int& ans){
    //vector<int>::iterator it;
    int index;
    vector<int> dp(n+1,inf);
    dp[0]=1000000007;
    for(int i=0;i<n;i++){
        index=upper(dp,c[i]);
        dp[index]=max(dp[index],c[i]);
    }
    ans=0;
    for(int i=1;i<=n;i++){
        if(dp[i]!=inf)ans++;
        else break;
    }
}

signed main(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    //reverse(c.begin(),c.end());
    int ans;
    lis(n,c,ans);
    cout<<ans<<endl;
    return 0;
}