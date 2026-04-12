#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<string> s(n);
  for (size_t i = 0; i < n; i++) cin >> s[i];
  vector<char> vec_inter(s[0].begin(), s[0].end());

  for (size_t i = 0; i < n; i++) {
    vector<char> si(s[i].begin(), s[i].end()), vec;
    sort(si.begin(),si.end());
    sort(vec_inter.begin(), vec_inter.end());
    set_intersection(vec_inter.begin(), vec_inter.end(), si.begin(), si.end(), back_inserter(vec));
    vec_inter = vec;
  }
  sort(vec_inter.begin(), vec_inter.end());
  string ans;
  for (size_t i = 0; i < vec_inter.size(); i++) ans.push_back(vec_inter[i]);
  cout << ans << endl;
  return 0;
}
