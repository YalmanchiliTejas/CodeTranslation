#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

#define M 998244353

int main(){
   int n, s;
   cin>>n>>s;
   vector<int> a(n);
   rep(i, n) cin>>a[i];

   vector<int> dp(s+1), ndp(s+1);
   int ans=0;
   rep(i, n){
      dp[0]+=1;
      rep(j, s+1){
         ndp[j]=(ndp[j]+dp[j])%M;
         int jj=j+a[i];
         if(jj<=s) ndp[jj]=(ndp[jj]+dp[j])%M;
      }
      ans=(ans+ndp[s])%M;
      swap(dp, ndp);
      ndp=vector<int>(s+1);
   }

   cout<<ans<<endl;

   return 0;                                                                                            }
