#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  char a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int c=0;
      int d=0;
      for(int k=0;k<m;k++){
        if(a[i][k]=='#'){
          c++;
        }
      }
      for(int l=0;l<n;l++){
        if(a[l][j]=='#'){
          d++;
        }
      }
      if(c==0||d==0){
        a[i][j]='2';
      }
    }
  }
  for(int i=0;i<n;i++){
    int count=0;
    for(int j=0;j<m;j++){
      if(a[i][j]!='2'){
        cout << a[i][j];
        count++;
      }
    }
    if(count!=0){
      cout << endl;
    }
  }
}