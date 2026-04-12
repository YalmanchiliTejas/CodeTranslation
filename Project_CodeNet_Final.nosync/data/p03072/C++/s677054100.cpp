#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 9223372036854775807
#define LONGLONGMIN -9223372036854775807
#define INTMAX 32767
#define INTMIN -32767
#define ROUNDUP(divisor,dividend) (divisor + (dividend - 1)) / dividend
int n,m,ans=0; std::vector<int> h;
int main(){
  cin >> n;
  h.resize(n);
  for (size_t i = 0; i < n; i++) {
    cin >> h[i];
    if(i==0 || h[i] >= m){
      ans++;
      m = h[i];
    }
  }
  cout << ans << endl;
}
