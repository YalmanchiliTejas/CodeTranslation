#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  
  vector<vector<char>>a(h,vector<char>(w));
  for(int i=0; i<h; i++){
   for(int j=0; j<w; j++){
     cin >> a[i][j];
   }
  }
  
  int count=0;
  for(int i=0; i<h; i++){
    int j=count;
    while(a[i][j]=='#'){
     count++;
     j++;
   }
    
    for(int ex=j+1; ex<h; ex++){
     if(a[i][ex]=='#'){
       cout << "Impossible" << endl;
       return 0; 
     }
    }
    
    
    for(int k=i+1; k<h; k++){
     for(int l=0; l<count-1; l++){
       if(a[k][l]=='#'){
         cout << "Impossible" << endl;
         return 0;
       }
     }
    }
  }
    
  cout << "Possible" << endl;
  
  return 0;
  
}
