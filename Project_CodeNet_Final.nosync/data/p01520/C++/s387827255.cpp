#include <iostream>
using namespace std;

int main(){
  int n,t,e,time,ans = -1;
  cin >> n >> t >> e;
  for(int i=1;i<=n;i++){
    cin >> time;
    for(int j=1;time*j<=t+e;j++){
      if(time*j >= t-e){
	ans = i;
	break;
      }
    }
  }
  cout << ans << endl;
}