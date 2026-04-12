#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
long long int mod = 1e9+7;

int main(){
  string s;
  int n, k; cin >> n >> s >> k;
  char c = s[k-1];
  for(int i=0; i<n; i++) {
    if(s[i] != c) s[i] = '*';
  }
  cout << s << endl;
  return 0;
}


// EOF
