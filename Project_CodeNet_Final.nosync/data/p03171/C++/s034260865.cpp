#include<bits/stdc++.h> 
#define ll long long
#define pb push_back
#define ld double
using namespace std;

ll dp[3001][3001];

ll solve(vector<int> &a, int l ,int r){
   if(l>=(int)a.size() || r < 0)
      return 0;
  if(l > r)
      return 0;
  if(dp[l][r]!=-1)
     return dp[l][r];
  if(l==r && l>=0 && l<a.size()){
     return a[l];
   }
   
    ll temp = a[l] + min(solve(a,l+2,r),solve(a,l+1,r-1));
    ll temp2 = a[r] + min(solve(a,l+1,r-1),solve(a,l,r-2));
  //if(l==0 && r == a.size()-1)
    //cout<<temp <<" "<< temp2<<"\n";
  return  dp[l][r]=max(temp, temp2);
}

int main(){
   int n;
   cin>>n;
  vector<int> a(n);
  ll tot=0;
  for(int i=0;i<n;i++){
  cin>>a[i];
    tot+=a[i];
  }
  for(int i=0;i<3001;i++)
    for(int j=0;j<3001;j++)
      dp[i][j]=-1;
  ll ans = solve(a,0,n-1); 
  cout<<2*ans-tot<<"\n";
return 0; 
}