// In god we trust

#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>


#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define INF 1000000000
#define int long long

using namespace std;
using namespace std::chrono;


signed main(){
  string s;
  cin >> s;
  bool a, b;
  a = b = false;
  for (int i = 0; i < 3; i++)
    if (s[i] == 'A')
      a = true;
    else
      b = true;
  if (a && b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
