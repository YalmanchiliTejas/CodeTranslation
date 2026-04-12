#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

const long long m = 1000000000 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  unsigned long long n;
  cin >> n;
  vector<unsigned long long> v(n);
  unsigned long long sum = 0;
  for(auto& el: v) {
    cin >> el;
    sum += el % m;
  }
  unsigned long long totalprod = 0;
  for(int i = 0; i < n - 1; i++) {
    sum -= v[i];
    totalprod += ((sum % m) * (v[i] %m)) % m;
  }
  cout << totalprod % m << "\n";
	return 0;
}
