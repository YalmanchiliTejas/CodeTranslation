#include <iostream>
using namespace std;
int main()
{
  int N,T,E;
  cin >> N >> T >> E;
  bool bfind = false;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    if(bfind) continue;
    for(int j=-E; j<=E; j++){
      if((T+j) % x == 0){
        bfind = true;
        cout << i+1 << endl;
        break;
      }
    }
  }
  if(!bfind){
    cout << -1 << endl;
  }
  return 0;
}