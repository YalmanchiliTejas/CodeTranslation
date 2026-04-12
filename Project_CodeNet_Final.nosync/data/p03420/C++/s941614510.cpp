        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

   int m[(1<<('z'-'a' +1))];
vector<pair<int,int>> k;
        signed main() {
     int n,k;
     cin>>n>>k;
     int ans=0;
     if(k==0){
             cout<<n*n;
             return 0;
     }
     for(int i=k+1;i<=n;i++){
             ans+=max(0ll,n%i -k+1)+(i-k)*(n/i);
            // cerr<<ans<<' ';
     }
     cout<<ans;

      
        


      }


        
