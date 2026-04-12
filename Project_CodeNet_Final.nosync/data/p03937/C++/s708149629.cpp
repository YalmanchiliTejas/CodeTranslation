#include <iostream>
using namespace std;
int main(void){
     int H,W ;
     cin >> H >> W ;
     char s[8][8] ;
     int count  = 0 ;
     for(int i=0;i<H;i++){
          for(int j=0;j<W;j++){
               cin >> s[i][j] ;
               if(s[i][j]=='#') count++ ;
          }
     } 
    
    if(count==H+W-1){
         cout << "Possible" ;
    }else{
         cout << "Impossible" ;
    }
        
}
