#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
int main() {
  long long k,a,b,ans,cnt;
  cin >> k >> a >> b;
  if(a>=k) {
    cout << 1 << endl;
  }
  else if(a<=b) {
    cout << -1 << endl;
  }
  else {
    cout << (k-b-1)/(a-b)*2+1 << endl;
  }
}
