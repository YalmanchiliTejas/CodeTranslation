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
  int count=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j]=='#'){
        count++;
      }
    }
  }
  cout << (count+1==n+m?"Possible":"Impossible") << endl;
}
    