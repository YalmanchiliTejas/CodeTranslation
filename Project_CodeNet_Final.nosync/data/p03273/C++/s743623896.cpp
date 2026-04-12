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
  char b[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      b[i][j]=a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int c=0;
      int d=0;
      for(int k=0;k<m;k++){
        if(b[i][k]=='#'){
          c++;
        }
      }
      for(int l=0;l<n;l++){
        if(b[l][j]=='#'){
          d++;
        }
      }
      if(c==0||d==0){
        b[i][j]='2';
      }
    }
  }
  for(int i=0;i<n;i++){
    int count=0;
    for(int j=0;j<m;j++){
      if(b[i][j]!='2'){
        cout << a[i][j];
        count++;
      }
    }
    if(count!=0){
      cout << endl;
    }
  }
}
