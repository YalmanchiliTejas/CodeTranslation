#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl
#define debugvec(v)   rep(i, v.size()) cerr << "L" << __LINE__ << ": " << #v << "[" << i << "] = " << v[i] << endl;
#define debugvec2(v)  cerr << "L" << __LINE__ << ": " << #v << " = { "; rep(i, v.size()) cerr << v[i] << (i + 1 == v.size() ? "" : ", "); cerr << " }" << endl;
typedef long long ll;  /* 10^18 くらいまでいける */

int main(){
  string s;
  cin >> s;

  // AかBしかない場合(A,Bのどちらかが文字列内に無い)はNo
  if (s.find("A")==string::npos || s.find("B")==string::npos)
    cout<< "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}