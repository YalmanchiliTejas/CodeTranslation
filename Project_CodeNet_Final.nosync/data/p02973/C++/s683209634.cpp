#include <iostream>
#include <set>
using namespace std;
multiset<int> ans;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto itr = ans.lower_bound(a);

    if(itr == ans.begin()) ans.insert(a);
    else {
      --itr;
      ans.erase(itr);
      ans.insert(a);
    }
  }

  /*for(auto itr = ans.begin(); itr != ans.end(); ++itr) {
    cout << *itr << endl;
    }*/

  cout << ans.size() << endl;
      
  
}
