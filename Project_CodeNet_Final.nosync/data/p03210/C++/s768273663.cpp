#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl
#define debugvec(v)   rep(i, v.size()) cerr << "L" << __LINE__ << ": " << #v << "[" << i << "] = " << v[i] << endl;
#define debugvec2(v)  cerr << "L" << __LINE__ << ": " << #v << " = { "; rep(i, v.size()) cerr << v[i] << (i + 1 == v.size() ? "" : ", "); cerr << " }" << endl;
typedef long long ll;  /* 10^18 くらいまでいける */

int main(){
  int x;
  cin >> x;

  if (x==3 || x==5 || x==7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}