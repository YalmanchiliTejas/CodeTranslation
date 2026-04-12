#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,x,y,X;
  X = 0;
  x=0,y=0;
  cin >> a >> b;
  char A[a][b];
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
       cin >> A[i][j];
    }
  }
   for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
       if(A[i][j] == '#'){
           cout << '#';
           X = 1;
       }else{
           for(int k=0;k<a;k++){
               if(A[k][j] == '#'){
                  x = 1;
                   break;
               }
           }
           for(int l=0;l<b;l++){
                  if(A[i][l] == '#'){
                    y = 1;
                    break;
                  }
            }
          if(x == 1 && y == 1){
              cout << '.';
              X = 1;
          }
          x = 0,y = 0;
        }
        }
        if(X != 0) cout << endl;
        X = 0;
    }
  }