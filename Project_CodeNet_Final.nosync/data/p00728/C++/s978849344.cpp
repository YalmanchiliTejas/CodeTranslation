#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
  int n;
  while(cin >> n && n) {
	vector<int> v(n, 0);
	for(int i = 0; i < n; ++i) {
	  cin >> v[i];
	}
	*min_element(v.begin(), v.begin() + n) = 0;
	*max_element(v.begin(), v.begin() + n) = 0;
	
	cout << accumulate(&v[0], &v[n], 0) / (n - 2) << endl;
  }

  return 0;
}