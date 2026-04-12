#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int x,y,z; cin >> x >> y >> z;

  int ans = 0;
  x-=z;
  do{
    ans++;
    x-=(y+z);
  }while(x>=y+z);
  
  cout << ans << endl;
  
  return 0;
}
