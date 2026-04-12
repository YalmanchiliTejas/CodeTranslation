#include <bits/stdc++.h>
using namespace std;
using f32 = float;
using f64 = double;
using LL = long long;
using ULL = unsigned long long;
#define REP(i, n) for (LL i = 0; i < (int)(n); i++)
signed main()
{ 
  string a;
    cin >>a;
  REP(i,2){
  if(a[i]!=a[i+1]){
  cout << "Yes";
  return 0;
  }
  }
  cout << "No";
  
}