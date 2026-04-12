#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "cmath"
typedef long long ll;

int main(int argc, char const *argv[]) {
  ll NN;

  std::cin >> NN;

  std::vector<ll> v(NN);

  for (size_t i = 0; i < NN; i++) {
    std::cin >> v[i];
  }

  std::sort(v.begin(), v.end());

  // for (size_t i = 0; i < NN; i++) {
  //   std::cout << v[i] << '\n';
  // }

  ll sum, r_num, l_num;
  ll small = 0, big = 0;
  for (size_t i = 0; i < NN; i++) {
    if (i == 0) {
      r_num = v[small];
      l_num = v[small];
      sum = 0;
      small += 1;
    }else{
      if (i%4 == 1 || i%4 == 2) {
        if (i%4 == 1) {
          sum += abs(r_num - v[NN -1 - big]);
          r_num = v[NN -1 - big];
          big +=1;
        }else{
          sum += abs(l_num - v[NN -1 - big]);
          l_num = v[NN -1 - big];
          big +=1;
        }
      }else{
        if (i%4 == 3) {
          sum += abs(r_num - v[small]);
          r_num = v[small];
          small +=1;
        }else{
          sum += abs(l_num - v[small]);
          l_num = v[small];
          small +=1;
        }
      }
    }
  }

  std::sort(v.begin(), v.end(), std::greater<int>());

  ll sum2;
  small = 0, big = 0;
  for (size_t i = 0; i < NN; i++) {
    if (i == 0) {
      r_num = v[small];
      l_num = v[small];
      sum2 = 0;
      small += 1;
    }else{
      if (i%4 == 1 || i%4 == 2) {
        if (i%4 == 1) {
          sum2 += abs(r_num - v[NN -1 - big]);
          r_num = v[NN -1 - big];
          big +=1;
        }else{
          sum2 += abs(l_num - v[NN -1 - big]);
          l_num = v[NN -1 - big];
          big +=1;
        }
      }else{
        if (i%4 == 3) {
          sum2 += abs(r_num - v[small]);
          r_num = v[small];
          small +=1;
        }else{
          sum2 += abs(l_num - v[small]);
          l_num = v[small];
          small +=1;
        }
      }
    }
  }

  if (sum < sum2) {
    sum = sum2;
  }

  std::cout << sum << '\n';

  return 0;
}
