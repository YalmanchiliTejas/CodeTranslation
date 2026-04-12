#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int num[31], rank[31];
map<int,int> m;

int main() {
  string str;
  fill(num, num+31, 0);
  while(cin >> str) {
    replace(str.begin(), str.end(), ',', ' ');
    stringstream ss;
    ss << str;
    int a, b;
    ss >> a >> b;
    if(a == 0 && b == 0) break;
    m[a] = b;
    ++num[b];
  }
  for(int i = 30, p = 1; i >= 0; --i) {
    if(num[i] != 0) rank[i] = p++;
  }

  int id;
  while(cin >> id) {
    cout << rank[m[id]] << endl;
  }
  return 0;
}