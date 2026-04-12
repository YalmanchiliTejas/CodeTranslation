#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int n;
  long hoge, sum = 0, sum1 = 0, sum2 = 0;
  std::vector<long> a;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> hoge;
    a.push_back(hoge);
  }
  std::sort(a.begin(), a.end(), std::greater<long>());

  for(int i = 0; i < n; i++){
    if(n % 2 == 0){
      if(i < n / 2 - 1) sum += a[i] * 2;
      else if(i == n / 2 - 1) sum += a[i];
      else if(i == n / 2) sum -= a[i];
      else sum -= a[i] * 2;
    }
    else{
      if(i < (n - 1) / 2 - 1) sum1 += a[i] * 2;
      else if(i == (n - 1) / 2 - 1) sum1 += a[i];
      else if(i == (n - 1) / 2) sum1 += a[i];
      else sum1 -= a[i] * 2;

      if(i < (n - 1) / 2) sum2 += a[i] * 2;
      else if(i == (n - 1) / 2) sum2 -= a[i];
      else if(i == (n - 1) / 2 + 1) sum2 -= a[i];
      else sum2 -= a[i] * 2;

      sum = std::max(sum1, sum2);
    }
  }
  std::cout << sum << std::endl;
}