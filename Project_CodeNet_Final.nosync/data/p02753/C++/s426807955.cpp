#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  string s;
  cin >> s;
  if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A')
    cout << "No" << endl;
  else if(s[0] == 'B' && s[1] == 'B' && s[2] == 'B')
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}