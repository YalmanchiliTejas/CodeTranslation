#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<cstring>
using namespace std;
long long int mod = 1e9 + 7;
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

int n;
long long int x;
long long int b[60];
long long int p[60];

void init() {
  b[0] = 1; p[0] = 1;
  for(int i=1; i<=n; i++){
    b[i] = 2*b[i-1] + 3;
    p[i] = 2*p[i-1] + 1;
  }
}

long long int f(int n, long long int x) {
  if(x == 0) return 0;
  else if(n == 0){
    return 1;
  } else if(x <= 1 + b[n-1]) {
    return f(n-1, x-1);
  } else {
    return p[n-1] + 1 + f(n-1, x-2-b[n-1]);
  }
}

int main() {
  cin >> n >> x;

  init();
  cout << f(n, x) << endl;

  return 0;
}



///
