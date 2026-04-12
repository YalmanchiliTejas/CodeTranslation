#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int M=1000000007;
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   int sum=0;
   for(int i=0;i<n;i++)
   sum=sum+a[i];

   int ans=0;
   vector<int>v;
for(int i=0;i<n-1;i++){
sum=sum-a[i];
ans=ans+(a[i]*(sum%M))%M;
ans=ans%M;

}

cout<<ans<<endl;
   
    return 0;
}