#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> ans(n);
  bool first[] = { true, false };
  bool second[] = { true, false };
  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
      ans[0] = first[x];
      ans[1] = second[y];
      for(int i = 2; i < n; i++){
        if(ans[i-1]){ // 隣が正直
          if(s[i-1] == 'o'){ // 両隣同じ
            ans[i] = ans[i-2];
          }else{
            ans[i] = !ans[i-2];
          }
        }else{
          if(s[i-1] == 'o'){
            ans[i] = !ans[i-2];
          }else{
            ans[i] = ans[i-2];
          }
        }
      }

      bool ok = true;

      for(int i = 0; i < n; i++){
        if(ans[i]){ // i が正直
          // cout << s[i] << ": " << ans[(i+1)%n] << ", " << ans[(n+i-1)%n] << endl;
          if(s[i] == 'o'){
            if(ans[(i+1)%n] != ans[(n+i-1)%n]){
              ok = false;
              break;
            }
          }else{
            if(ans[(i+1)%n] == ans[(n+i-1)%n]){
              ok = false;
              break;
            }
          }
        }else{
          if(s[i] == 'o'){
            if(ans[(i+1)%n] == ans[(n+i-1)%n]){
              ok = false;
              break;
            }
          }else{
            if(ans[(i+1)%n] != ans[(n+i-1)%n]){
              ok = false;
              break;
            }
          }
        }
      }

      if(!ok) continue;

      for(int i = 0; i < n; i++){
        if(ans[i]){
          cout << 'S';
        }else{
          cout << 'W';
        }
      }
      cout << endl;
      return 0;
      // if(ans[0]){ // 最初が正直
      //   if(s[0] == 'o'){
      //     if(ans[1] != ans[n-1]){
      //       continue;
      //     }
      //   }else{
      //     if(ans[1] == ans[n-1]){
      //       continue;
      //     }
      //   }
      // }else{
      //   if(s[0] == 'o'){
      //     if(ans[1] == ans[n-1]){
      //       continue;
      //     }
      //   }else{
      //     if(ans[1] != ans[n-1]){
      //       continue;
      //     }
      //   }
      // }
      // if(ans[n-1]){

      // }
    }
  }
  cout << -1 << endl;
}
