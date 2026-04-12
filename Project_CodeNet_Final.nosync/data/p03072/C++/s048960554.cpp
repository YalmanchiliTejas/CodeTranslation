#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)


int main(){
  int n;
  int H[30];
  cin >> n;
  rep(i, n)cin >> H[i];
  int tmp = H[0];
  int ans = 1;
  for(int i=1;i<n;i++){
    
	if(tmp>H[i])continue;
    ans++;
    tmp = max(tmp, H[i]);
  }
  cout << ans << endl;

  return 0;
}
