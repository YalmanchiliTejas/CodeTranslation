#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;

int main ()
{
  prep();
  int n;
  cin >> n;
  long long arr[n];
  bool over2 = false;
  for (int i=0; i<n; i++){
      cin >> arr[i];
      if (arr[i] >= n){
          over2 =true;
      }
  }
  if (!over2){
      cout << 0;
      return 0;
  }
  long long times = 0;
  while (true){
      long long sums[n];
      long long tot = 0;
      for (int i=0; i<n; i++){
          long long left = max(0LL, arr[i]-(n-1));
          long long num = left/n+(left%n != 0);
          arr[i] -= num*n;
          sums[i] = num;
          tot += num;
          times += num;
      }
      bool over = false;
      for (int i=0; i<n; i++){
          arr[i] += tot-sums[i];
          if (arr[i] >= n){
              over = true;
          }
      }
      if (!over){
          break;
      }
  }
  cout << times;
  return 0; 
}
