#include<bits/stdc++.h>
using namespace std;
# define ll long long int
ll dp[3001][3001];
//vector<int>v;
ll rec(ll s, ll e, ll arr[],ll i)
{
  if(s>e)
  {
    //return arr[s];
    return 0;
  }

  if(dp[s][e]!=-1)
  {
    return dp[s][e];
  }

 if(i%2==0)
 {

    return dp[s][e]=max(arr[s]+rec(s+1,e,arr,i+1),arr[e]+rec(s,e-1,arr,i+1));
 }
 else{
   return dp[s][e]=min(rec(s+1,e,arr,i+1),rec(s,e-1,arr,i+1));
 }

 //return dp[s][e];
  //return v[v.size()-1];
}

int main()
{

  int n;
  cin>>n;
  ll arr[n];
  ll sum1=0;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    sum1+=arr[i];
  }
  //cout<<"sum "<<sum1<<endl;
  memset(dp,-1,sizeof(dp));
  ll taro=rec(0,n-1,arr,0);
  //cout<<"Taro "<<taro<<endl;
  ll jiro= sum1-taro;
  cout<<taro-jiro<<endl;
// cout<<"Beginning of list "<<endl;
// for(int i=0;i<v.size();i++)
// {
//   cout<<v[i]<<endl;
// }
}
