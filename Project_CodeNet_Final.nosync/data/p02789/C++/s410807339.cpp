#ifdef HIRO
#include "../stdc++.h"
#define d(f_, ...) printf((f_), ##__VA_ARGS__)
#else
#include <bits/stdc++.h>
#define d(f_, ...)
#endif

using namespace std;
typedef long long ll;

int main() {
#ifdef HIRO
  string file_path(QUIZ);
  ifstream cin(file_path + "/input.txt");
  std::cin.rdbuf(cin.rdbuf());
#endif
  int n;
  int m;
  cin >> n;
  cin >> m;
  
  if(n==m)
    cout << "Yes";
  else
    cout << "No";

  // cout << ans << endl;
  return 0;
}

