#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,m;
     cin >>n>>m;
     vector<vector<int>> v(m,vector<int>(2));

     for(int i=0;i<m;i++){
       cin >> v[i][0] >> v[i][1];
     }

     vector<int> order(n-1);
     for(int i=0;i<n-1;i++){
       order[i]= i+2;
     }

     int cnt=0,ans=0,c=0;
     bool b =false;

     do {
       cnt =0;
       for(int i=0;i<n-2;i++){
         b =false;
         for(int j=0;j<m;j++){
           if((order[i]==v[j][0]&&order[i+1]==v[j][1])||(order[i]==v[j][1]&&order[i+1]==v[j][0])) b = true;
         }
         if(b) cnt++;
       }

       c = 0;
       if(cnt==n-2){
         for(int k=0;k<m;k++){
        if((v[k][0]==1&&v[k][1]==order[0])||(v[k][1]==1&&v[k][0]==order[0])) c++;
       }
     }
       if(!(c==0)) ans++;



    } while(next_permutation(order.begin(),order.end()));
     cout << ans << endl;

}