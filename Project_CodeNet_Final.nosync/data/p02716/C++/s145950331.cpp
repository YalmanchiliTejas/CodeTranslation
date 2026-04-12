        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  1000000007;

     signed main(){
     
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==2){
         cout<<max(a[0],a[1])<<endl;
         return 0;
    }
    int x[n][3];
    x[0][0]=a[0];x[0][1]=MOD*MOD;x[0][2]=MOD*MOD;
    x[1][0]=MOD*MOD;x[1][1]=a[1];x[1][2]=MOD*MOD;
    x[2][0]=a[0]+a[2];x[2][1]=MOD*MOD;x[2][2]=a[2];
    x[3][0]=MOD*MOD;x[3][1]=max(a[1],a[0])+a[3];x[3][2]=MOD*MOD;
    for(int i=4;i<n;i++){
      
              if(x[i-2][0]!=MOD*MOD)x[i][0]=x[i-2][0]+a[i];
              else x[i][0]=MOD*MOD;
         
        
            if(x[i-3][0]!=MOD*MOD)  x[i][1]=x[i-3][0]+a[i];
            else x[i][1]=MOD*MOD;
             if(x[i-3][1]!=MOD*MOD)  x[i][2]=x[i-3][1]+a[i];
            else x[i][2]=MOD*MOD;

        if(x[i-4][0]!=MOD*MOD){
             if(x[i][2]!=MOD*MOD)x[i][2]=max(x[i][2],x[i-4][0]+a[i]);
             else x[i][2]=x[i-4][0]+a[i];
        }
        if(x[i][2]!=MOD*MOD)x[i][2]=max(x[i][2],x[i-2][2]+a[i]);
      else x[i][2]=x[i-2][2]+a[i];
       if(x[i][1]!=MOD*MOD)x[i][1]=max(x[i][1],x[i-2][1]+a[i]);
      else x[i][1]=x[i-2][1]+a[i];
    }
    if(n%2){
         if(n==3)cout<<x[n-2][1]<<endl;
        else  cout<<max(x[n-2][1],x[n-1][2])<<endl;
    }else{
         cout<<max(x[n-2][0],x[n-1][1])<<endl;
       //  cerr<<x[n-2][0]<<' '<<x[n-1][1]<<endl;
    }
      }

        
