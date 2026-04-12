#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> a;
  int n,num;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> num;
    a.push_back(num);
    //cout << num << endl;
  }

  int q,k;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> k;
    auto itr_b = a.begin();
    auto itr_e = a.end();
    auto itr = lower_bound(itr_b, itr_e, k);
    size_t pos = distance(itr_b, itr);
    cout << pos << endl;
  }

  return 0;
}

