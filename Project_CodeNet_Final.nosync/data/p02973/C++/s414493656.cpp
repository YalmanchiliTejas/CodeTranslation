#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int binary_search(int x)
{
  int l = 0, r = v.size(), mid;
  while (l < r) {
    mid = (l+r)/2;
    if (v[mid] >= x) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}
  
int main()
{
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int id = binary_search(a);
    if (id == v.size()) {
      v.push_back(a);
    } else {
      v[id] = a;
    }
  }
  
  cout << v.size() << endl;
  return 0;
}