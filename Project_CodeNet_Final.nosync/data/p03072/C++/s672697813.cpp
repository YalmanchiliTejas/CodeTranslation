#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v_list;

int main() {
  cin >> N;
  v_list.resize(N);
  for(int i=0;i<N;i++) cin >> v_list[i];

  int ans   = 0;
  int pre_h = 0;
  for(int i=0;i<N;i++) {
    if (pre_h <= v_list[i]) {
      pre_h = v_list[i];
      ans++;
    }
  }
  cout << ans << "\n";

#if 0
  cout << N << " " << "\n";
  for(auto s: v_list) cout << s << " "; 
  cout << "\n" ;
#endif
  return 0;
}