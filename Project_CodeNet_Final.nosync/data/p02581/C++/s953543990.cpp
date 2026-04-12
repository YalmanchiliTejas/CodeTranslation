        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
    const int MAX =200002;
const int MOD =1000000007;

     signed main(){
     int n;
     cin>>n;
     int dp[n][n];
     for(int i=0;i<n;i++)fill(dp[i],dp[i]+n,-MOD*MOD);
      int mx[n],mmx=-MOD*MOD;fill(mx,mx+n,-MOD*MOD);
     int a[3*n],ans2=0;
     for(int i=0;i<3*n;i++){
         cin>>a[i];
         a[i]--;
     }
     dp[a[0]][a[1]]=0;dp[a[1]][a[0]]=0;
     mx[a[0]]=0;mx[a[1]]=0;mmx=0;
     for(int m=0;m<n-1;m++){
         int t=0;
         if(a[3*m+2]==a[3*m+3]&&a[3*m+3]==a[3*m+4]){t=1;ans2++;}
         int z[3];
         for(int i=0;i<3;i++)z[i]=dp[a[3*m+2+i]][a[3*m+2+i]]+1-t;
         if(t==0){
             for(int i=0;i<3;i++){
                 int j=(i+1)%3;
                 int k=(j+1)%3;
                 if(a[3*m+2+i]==a[3*m+2+j]){
                     int b[n];
                     for(int i0=0;i0<n;i0++)b[i0]=dp[a[3*m+2+i]][i0]+1;
                     for(int i0=0;i0<n;i0++){
                         dp[a[3*m+2+k]][i0]=max(b[i0], dp[a[3*m+2+k]][i0]);
                         dp[i0][a[3*m+2+k]]=dp[a[3*m+2+k]][i0];
                     }
                 }
             }
         }
         for(int i=0;i<3;i++){
             int j=(i+1)%3;
             int k=(j+1)%3;
            dp[a[3*m+2+j]][a[3*m+2+k]]=max(dp[a[3*m+2+j]][a[3*m+2+k]],z[i]);
            dp[a[3*m+2+k]][a[3*m+2+j]]=dp[a[3*m+2+j]][a[3*m+2+k]];
         }
         for(int i=0;i<3;i++){
            for(int i0=0;i0<n;i0++) {
                dp[a[3*m+2+i]][i0]=max(dp[a[3*m+2+i]][i0],mx[i0]-t);
                dp[i0][a[3*m+2+i]]=dp[a[3*m+2+i]][i0];
            }
         }
         for(int i=0;i<3;i++){
             int j=(i+1)%3;
             dp[a[3*m+2+i]][a[3*m+2+j]]=max(dp[a[3*m+2+i]][a[3*m+2+j]],mmx-t);
             dp[a[3*m+2+j]][a[3*m+2+i]]=max(dp[a[3*m+2+j]][a[3*m+2+i]],mmx-t);
         }
         for(int i=0;i<3;i++)for(int i0=0;i0<n;i0++){
             mx[i0]=max(mx[i0],dp[a[3*m+2+i]][i0]);
             mmx=max(mx[i0],mmx);
             mx[a[3*m+2+i]]=max(mx[a[3*m+2+i]],dp[a[3*m+2+i]][i0]);
         }


     }
     cout<<max(mmx,dp[a[3*n-1]][a[3*n-1]]+1)+ans2<<endl;
     

     }


 


 






    





      

        
