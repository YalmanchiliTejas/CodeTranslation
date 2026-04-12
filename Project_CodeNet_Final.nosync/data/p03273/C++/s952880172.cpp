#include <bits/stdc++.h>
using namespace std;

int main() {
int n,m;
  cin >> n >> m;
  vector<string> a(n);

  for(int i=0;i<n;i++){
   cin >> a[i];
  }

  vector<bool> yoko(n,false);
  vector<bool> tate(m,false);

  for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
      if(a[i][j]=='#'){
       yoko[i]=true;tate[j]=true;
      }
     }
  }

  for(int i=0;i<n;i++){
    if(yoko[i]){
      for(int j=0;j<m;j++){
       if(tate[j])cout << a[i][j];
      }
      cout << endl;
    }
  }

}
