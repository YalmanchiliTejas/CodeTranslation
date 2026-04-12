#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _count(i, a, b) for (int i = (a); i <= b; i++)
#define PB emplace_back
#define MINI -2147483648
#define MAXI 2147483647
#define MAXLL 9223372036854775807
#define MINLL -9223372036854775808
#define VI vector<int>
#define VB vector<bool>
#define VLL vector<long long>
#define LL long long
#define ULL unsigned long long
#define ALL(X) X.begin(), X.end() 
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
//#define Remilia_is_so_cute
#define StarBurst std::ios::sync_with_stdio(false),cin.tie(NULL);
#define lowerBit(x) x&-x
using namespace std;
 
inline void R_P(vector<int> &vec) {
  int temp;
  cin>>temp;
  vec.push_back(temp);
} 
inline bool checkMax(int &base, int test) {
  return (test > base) ? base = test, true : false; 
}
 
inline bool checkMin(int &base, int test){
  return (test < base)? base = test, true : false;
}
template <class T>
void test(vector<T> &vec, const string &warn) {
  cout<<warn<<'\n';
  _for(i, 0, vec.size())
    cout<<vec[i]<<' ';
  cout<<"\nTest end..............\n";
}
 
int n;
int main () {
  StarBurst
  #ifdef Remilia_is_so_cute
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  cin >> n;
  VLL vec(n + 1, 0);
  VLL prefix(n + 1, 0);
  _count(i, 1, n) {
    cin >> vec[i];
    prefix[i] = (prefix[i - 1] + vec[i]) % 1000000007;
  }
  //test(prefix, "aa");
  LL ans = 0;
  _for(i, 1, n) {
    int tmp = prefix[n] - prefix[i];
    if (tmp < 0)
      tmp += 1000000007;
    ans += vec[i] * tmp;
    //cout << vec[i] << ' ' << prefix[n] << ' ' << prefix[i] << '\n';
    ans %= 1000000007;
  }

  cout << ans << '\n';
 
  return 0;
}