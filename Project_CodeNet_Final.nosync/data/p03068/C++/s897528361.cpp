#include<iostream>
#include<string>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  for (char& c : s) {
    if (s[k - 1] != c) c = '*';
  }
  cout << s << endl;
}
