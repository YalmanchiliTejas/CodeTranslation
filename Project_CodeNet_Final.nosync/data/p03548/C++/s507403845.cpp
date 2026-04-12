#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <climits>
using namespace std;
using P = pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x,y,z;
  cin >> x >> y >> z;
  int ans = 0;
  for(int i=1; i<=x; i++){
    if((long long)y*i + z*(i+1) <= x){
      ans = i;
    }
  }
  cout << ans << "\n";
  return 0;
}