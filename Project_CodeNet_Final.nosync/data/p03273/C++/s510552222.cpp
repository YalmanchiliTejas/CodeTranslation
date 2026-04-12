#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m;cin>>n>>m;
    char a[n][m];
    for(int i = 0;i<n;i++){
      string b;cin>>b;
      for(int j = 0;j<m;j++) {
       a[i][j] = b[j];
      }
    }
    for(int i = 0;i<n;i++){
      bool kesu = true;
      for(int j = 0;j<m;j++){
        if(a[i][j] == '#'){
          kesu = false;
          break;
        }
      }
      if(kesu){
        for(int o = 0;o<m;o++){
          a[i][o] = 'a';
        }
      }
    }
    for(int i = 0;i<m;i++){
      bool kesu = true;
      for(int j = 0;j<n;j++){
        if(a[j][i] == '#'){
          kesu = false;
          break;
        }
      }
      if(kesu){
        for(int o = 0;o<n;o++){
          a[o][i] = 'a';
        }
      }
    }
    for(int i = 0;i<n;i++){
      int kita = 0;
      for(int j = 0;j<m;j++) {
        if(a[i][j] != 'a'){
          cout<<a[i][j];
          kita +=1;
        }
      }
      if(kita>0)cout<<""<<endl;
    }
    return 0;
}