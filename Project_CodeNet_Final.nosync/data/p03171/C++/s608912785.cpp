#include<bits/stdc++.h>
#define w while
#define loop(i,l,r) for(int i=l;i<r;i++)
#define ci cin>>
#define co cout<<
#define mm 1000000007
#define ll long long
using namespace std;
ll int helper( vector<vector<ll int>> &dp,vector<ll int> &vec ,int start,int last ){
  if(start>last){
    return 0;}
    if(start==last)
    return vec[start];
    if(last-start==1)
      return max(vec[last],vec[start]);

    if(dp[start][last]!=-1)
    return dp[start][last];

  ll  int a  = vec[start] + min( helper(dp,vec,start+2,last ) , helper(dp,vec,start+1,last-1 ) );
   ll int b= vec[last]+min(helper(dp,vec,start+1,last-1),helper(dp,vec,start,last-2) );
        dp[start][last]=max(a,b);
   return max(a,b);
}
int main()
 {  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int n;
     cin>>n;
     ll int sum=0;
   vector<ll int>vec(n);
    for(int i=0;i<n;i++){
      cin>>vec[i];
    sum+=vec[i];
  }
  vector<vector<ll int>>dp(n,vector<ll int>(n,-1));
   ll int taro = helper(dp,vec,0,n-1);
   cout<<( taro - sum + taro );
}
