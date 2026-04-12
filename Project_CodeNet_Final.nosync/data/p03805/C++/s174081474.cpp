#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  int per[n];
  for(int i = 0; i < n; i++){
    per[i] = i + 1;
  }
  int edge[m][2];
  for(int i = 0; i < m; i++){
    for(int j = 0; j < 2; j++){
      cin >> edge[i][j];
    }
  }
  int ans = 0; 
  do{
    if(per[0] != 1) break; //スタートが１
    bool ok;
    for(int i = 0; i < n - 1; i++){ //perのindex
      ok = false;
      for(int j = 0; j < m; j++){
        if(edge[j][0] == per[i] && edge[j][1] == per[i+1]){
          ok = true;
          break;
        }
        else if(edge[j][1] == per[i] && edge[j][0] == per[i+1]){
          ok = true;
          break;
        }
      }
      if(!ok) break; //あるiで違うなら順列組み替え
    }
    if(ok) ans++;//最後までok = trueならカウント
  }while(next_permutation(per, per + n));
  cout << ans << endl;
}
      