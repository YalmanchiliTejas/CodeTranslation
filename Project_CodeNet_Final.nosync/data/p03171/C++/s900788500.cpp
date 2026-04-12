
/*
   Author: @yash_31
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#define ll long long int
#define eb emplace_back
#define pb push_back
#define fatafat ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define ft first
#define sd second
#define vpi vector<pair<int,int> >
#define vpl vector<pair<ll,ll> >
#define mkpr make_pair
#define todec() to_ulong()
#define toldec() to_ullong()
#define deb(x) std::cout<<#x<<":"<<x<<endl;
#define whole(x) (x).begin(),(x).end()
#define revwhole(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define sp " "
#define fbo find_by_order
#define ook order_of_key
 
using namespace std; 
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> gharKaSet;
 
const ll inf=1e12;
 
// same as CSES que

pair<ll,ll> dp[5000][5000];
vector<ll> arr;
vector<ll> prefixs;
 
pair<ll,ll> getRes(int i,int j){
   if(i==j){return mkpr(arr[i],0);}
   else if(dp[i][j].ft!=-inf){return dp[i][j];}
   else {
      dp[i][j].ft=max(getRes(i,i).ft+getRes(i+1,j).sd,getRes(j,j).ft+getRes(i,j-1).sd);
      dp[i][j].sd=prefixs[j]-prefixs[i]+arr[i]-dp[i][j].ft;
      // dp[i][j].sd=min(getRes(i,i).ft+getRes(i+1,j).sd,getRes(j,j).ft+getRes(i,j-1).sd);
      return dp[i][j];
   }
}
 
int main()
{
   fatafat
   int n;
   cin>>n;
   arr.resize(n);
   prefixs.resize(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   prefixs[0]=arr[0];
   for(int i=1;i<n;i++){prefixs[i]=prefixs[i-1]+arr[i];}
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(i==j){dp[i][i].ft=arr[i];dp[i][i].sd=0;}
         else{
            dp[i][j].ft=dp[i][j].sd=-inf;
         }
      }
   }
   auto val = getRes(0,n-1);
   cout<<val.ft-val.sd;
   return 0;
}