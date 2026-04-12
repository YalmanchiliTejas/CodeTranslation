#include <iostream>
#include <string>

#define MODIFIER (1'000'000'007)

long long int add(long long int x, long long int y) {
  return ((x % MODIFIER) + (y % MODIFIER)) % MODIFIER;
}

long long int multiply(long long int x, long long int y) {
  return ((x % MODIFIER) * (y % MODIFIER)) % MODIFIER;
}

int main() {

  int N;
  std::cin >> N;

  int A[200'000];
  long long int sumASoFar = 0;
  long long int sum = 0;

  for (int i=0; i<N; ++i) {
    int t;
    std::cin >> t;
    sum = add(sum, multiply(t, sumASoFar));
    sumASoFar += t;
  }

  std::cout << sum << std::endl;

  return 0;

}
