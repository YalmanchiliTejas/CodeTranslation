#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
void solve() {
     
     long int n;
     cin>>n;

     vector<long long int>a(n);
     long long int sum=0;
     for(long int i=0;i<n;i++) {
           cin>>a[i];
           sum= (sum+a[i]) % mod;
     }
     sum=sum-a[0];
     if(sum < 0) sum+=mod;

     long long int s=0;
     for(int i=0;i<n-1;i++) {
           s=(s + (a[i]*sum)%mod) % mod;
           sum-=a[i+1];
           if(sum < 0 ) sum+=mod;
     }

   cout<<s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
     freopen("in.txt","r",stdin);
      
     #endif

     int t;
     t=1;
     while(t--) solve();


   return 0;
}
