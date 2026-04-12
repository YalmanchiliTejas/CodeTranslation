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
long long mod = 998244353;
 
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
const int biggg = 2000000000;
const long long bigggest = 1000000000000000000LL;
const double eps = .0000000001; 

int main ()
{
  prep();
  string s;
  cin >> s;
  int acnt = 0;
  for (char c : s) if (c == 'A') acnt++;
  if (acnt < 3 && acnt) cout << "Yes";
  else cout << "No";
  return 0;
}