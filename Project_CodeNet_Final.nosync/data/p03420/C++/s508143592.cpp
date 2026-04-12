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

int main() {
  int n, k;
  cin >> n >> k;
  long long int cnt = 0;

  for(int b=1; b<=n; b++){
    long long int tmp = 0;

    tmp += max(0, b-k) * (n / b);
    tmp += max(0, n%b - k + 1);
    cnt += tmp;
  }
  for(int b=1; b<=n; b++){
    if(0%b >= k) cnt--;
  }
  cout << cnt << endl;

  return 0;
}
