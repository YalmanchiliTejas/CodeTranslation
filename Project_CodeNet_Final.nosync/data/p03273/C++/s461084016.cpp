#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    int H , W ;
    cin >> H >> W ;
    char a[H][W];
    bool b[H][W];
    int count = 0 ;

    for( int i = 0; i < H ; i++){
        for(int j = 0; j < W ; j++){
            cin >> a[i][j] ;
           if(a[i][j] == '.' ){
               count++ ;
           }
        }

        if(count == W ){
            for(int m = 0; m <W ;m++){
                b[i][m] = false ;
              }
         }else{
             for(int n = 0; n < W; n ++ ){
                 b[i][n] = true ;
              }
        }
        count = 0 ;
    }


    for( int k = 0; k < W ; k++){
        for(int l = 0; l < H ; l++){
        
           if(a[l][k] == '.' ){
               count++ ;
           }
        }

        if(count == H ){
             for(int o = 0; o <H ;o++){
                b[o][k] = false ;
             }
        }

           
        
        count = 0 ;
    }
    
    for(int q = 0; q < H ; q++ ){
        for(int r = 0; r < W; r ++){
            if(b[q][r] == true){
                cout << a[q][r] ;
            }
        }
        cout << endl;
    }

    return 0;
}