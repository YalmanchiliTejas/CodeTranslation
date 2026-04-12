#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n,m;
  cin >> n >> m;
  vector<string> a(n);
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }

  vector<bool> row(n,false);
  vector<bool> col(m,false);
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i = 0;i < n;i++){
    if(row[i]){
      for(int j = 0;j < m;j++){
        if(col[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }

}
