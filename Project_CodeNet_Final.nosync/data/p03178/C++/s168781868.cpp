#include <bits/stdc++.h>

using namespace std;

template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
  }
};
template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};


int main(){
  function<int(int, int)> add = [](int a, int b)->int{
    static int mod = 1e9 + 7;
    a %= mod;
    b %= mod;
    return (((a + b) % mod) + mod) % mod;
  };
  string K;
  assert(cin >> K);
  int D;
  assert(cin >> D);
  int N = (int) K.size();
  Vec <3,int> memo(N + 1, D, 2, -1);
  function <int(int, int, int)> dp = [&dp, &add, &K, &D, &N, &memo](int digit, int reminder, int state)->int{
    if(digit == N)return reminder == 0;
    int &ret = memo[digit][reminder][state];
    if(ret != -1)return ret;
    ret = 0;
    if(state){
      for(int i = 0; i <= 9; i++){
        ret = add(ret, dp(digit + 1, (reminder + i) % D, 1));
      }
    }else{
      ret = add(ret, dp(digit + 1, (reminder + K[digit] - '0') % D, 0));
      for(int i = 0; i < K[digit] - '0'; i++){
        ret = add(ret, dp(digit + 1, (reminder + i) % D, 1));
      }
    }
    return ret;
  };
  cout << add(dp(0, 0, 0), -1) << '\n';
  return 0;
}
