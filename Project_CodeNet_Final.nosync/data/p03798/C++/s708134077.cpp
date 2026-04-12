#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}

const int S = 0;
const int W = 1;
char i2c[2] = {'S', 'W'};

int animal[100010];

int next_animal(string &s, int i) {
  int m = s.size();
  char a = s[i+1];
  if (a == 'o' && animal[i+1] == S) return animal[(i+m)%m];
  if (a == 'x' && animal[i+1] == W) return animal[(i+m)%m];
  // a == 'o' && animal[i+1] == W
  // a == 'x' && animal[i+1] == S
  return 1-animal[(i+m)%m];
}

bool exists(string &s, int first, int second) {
  animal[0] = first;
  animal[1] = second;
  for (int i = 0; i < s.size()-2; ++i) { 
    animal[i+2] = next_animal(s, i);
  }
  if (next_animal(s, s.size()-2) != animal[0]) return false;
  if (next_animal(s, -1) != animal[1]) return false;
  return true;
}

void write(int n) {
  for (int i = 0; i < n; ++i) {
    cout << i2c[animal[i]];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (exists(s, S, S)) { write(n); return 0; }
  if (exists(s, S, W)) { write(n); return 0; }
  if (exists(s, W, W)) { write(n); return 0; }
  if (exists(s, W, S)) { write(n); return 0; }
  cout << "-1" << endl;
}

