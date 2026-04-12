    #include <iostream>
    #include <string>
    #include <math.h>
    #include<algorithm>
    using namespace std;
     
    int main(){
      int H, W;
      cin >> H >> W;
      char a[H][W];
      for(int i=0;i<H;i++){
       for(int j=0;j<W;j++){
        cin >> a[i][j]; 
       }
      }
      for(int i=0;i<H;i++){
       for(int j=0;j<W;j++){
         bool flag1=true;
         bool flag2=true;
         for(int k=0;k<W;k++){
          if(a[i][k]=='#'){
           flag1=false; 
          }
         }
         for(int k=0;k<H;k++){
           if(a[k][j]=='#'){
            flag2=false; 
           }
         }
           if(flag1==false && flag2==false){
            cout << a[i][j]; 
           }
        if(j==W-1 &&( flag1==false || flag2==false) ){
         cout << endl; 
        }
         }
       }

      return 0;}