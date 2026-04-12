#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
  ll N;
  cin >> N;
  map<char, ll> sum;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    map<char, ll> m;
    for(int j = 0; j < s.size(); j++) {
      m[s[j]]++;
    }
    if (i == 0) {
      sum = m;
    } else {
      for (auto itr = sum.begin(); itr != sum.end(); itr++) {
        sum[itr->first] = min(sum[itr->first], m[itr->first]);
      }
    }
  }
  string ret = "";
  for (auto itr = sum.begin(); itr != sum.end(); itr++) {
    for (int i = 0; i < itr->second; i++) {
      ret += itr->first;
    }
  }
  cout << ret << endl;
  return 0;
}
