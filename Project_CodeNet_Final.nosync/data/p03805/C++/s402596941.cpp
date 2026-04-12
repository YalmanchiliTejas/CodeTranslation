#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  int N ,M;
  cin >> N >> M;
  
  vector<vector<bool>> G(10, vector<bool>(10));
  rep (i, M)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G.at(a).at(b) = G.at(b).at(a) = true; 
  }
  
  vector<int> ord(N);
  rep (i, N)
  {
    ord.at(i) = i;
  }
  
  int count = 0;
  do {
    if (ord.at(0) != 0)
      break;
  	bool ok = true;
    for (int i = 0; i < N - 1; i++)
    {
      if(G.at(ord.at(i)).at(ord.at(i+1)) != true)
      {
        ok = false;
      }
    }
    if (ok == true)
    {
      count++;
    }
  } while (next_permutation(ord.begin(), ord.end()));
  cout << count << endl;
  
}