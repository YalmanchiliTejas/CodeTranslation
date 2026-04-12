using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define rep(i, n) for (int i=0; i<n; i++)
string s;
int n,k;

int main() {
  cin >> n >> s >> k;
  char c = s[k-1];
  rep(i, n) {
    char t = s[i]==c?c:'*';
    cout << t;
  }
  cout << endl;
  return 0;
}