#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
int main(){
  int N, T, E;
  cin >> N >> T >> E;
  int Time;
  int ans = 0;
  int x;
  for(int i = 1 ; i <= N ; i++){
    cin >> Time;
    for(int j = 1 ; Time*j <= T+E ; j++){
      x = Time * j;
      if(T - E <= x && x <= T + E){
	ans = i;
	break;
      }
    }
  }
  if(ans == 0) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}