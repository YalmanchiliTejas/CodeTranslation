#include <iostream>
using namespace std;

#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
  int n,hst,ans,h;
  
  hst = ans = 0;
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> h;
    if (h>=hst) ans++;
    hst = MAX(hst,h);
  }
  cout << ans << endl;
  return 0;
}