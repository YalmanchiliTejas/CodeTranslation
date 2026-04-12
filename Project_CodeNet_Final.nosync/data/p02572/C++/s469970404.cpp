#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7
        ;
int main() {
    IO;
   int n ;
   cin>>n ;
   vector<int>vec(n);
   ll sum = 0 ;
   for(int i = 0 ;i<n ; i++){
       cin>>vec[i];
       sum+=vec[i];
       sum%=MOD;
   }
   ll ans = 0;
   for(int i = 0;i<n ; i++){
       sum-=vec[i];
       if(sum<0)sum+=MOD;
       ans+=(sum*vec[i]);
       ans%=MOD;
   }
   cout<<ans<<endl;

}