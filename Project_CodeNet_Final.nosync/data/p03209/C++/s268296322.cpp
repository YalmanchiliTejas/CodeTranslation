#include <bits/stdc++.h>

std::vector<uint64_t> NumberOfBurgerLayer;
std::vector<uint64_t> NumberOfBurgerPatty;

void init(uint64_t N)
{
  NumberOfBurgerLayer = std::vector<uint64_t>(N + 1, 0);
  NumberOfBurgerPatty = std::vector<uint64_t>(N + 1, 0);
  
  NumberOfBurgerLayer[0] = 1;
  NumberOfBurgerPatty[0] = 1;
  for (uint64_t n = 0; n < N; ++n) {
    NumberOfBurgerLayer[n + 1] = 2 * NumberOfBurgerLayer[n] + 3;
    NumberOfBurgerPatty[n + 1] = 2 * NumberOfBurgerPatty[n] + 1;
  }
}

// index
// |
// v
// [ B ] :: [ f(n - 1) ] :: [ P ] :: [ f(n - 1) ] :: [ B ]
// <-1->    <- l(n-1) ->    <-1->    <- l(n-1) ->    <-1->

uint64_t search(uint64_t N, uint64_t X)
{
  if (N == 0) {
    return 1;
  }
  
  if (X < 1) {
    return 0;
  } else if (X < 1 + NumberOfBurgerLayer[N - 1]) {
    return search(N - 1, X - 1);
  } else if (X < 2 + NumberOfBurgerLayer[N - 1]) {
    return NumberOfBurgerPatty[N - 1] + 1;
  } else if (X < 2 + 2 * NumberOfBurgerLayer[N - 1]) {
    uint64_t Y = X - (2 + NumberOfBurgerLayer[N - 1]);
    return NumberOfBurgerPatty[N - 1] + 1 + search(N - 1, Y);
  } else if (X < 3 + 2 * NumberOfBurgerLayer[N - 1]) {
    return NumberOfBurgerPatty[N];
  }
  
  return -1;
}

int main()
{
  uint64_t N, X;
  std::cin >> N >> X;
  
  init(N);
  
  uint64_t patties = search(N, X - 1);
  std::cout << patties << std::endl;
  
  return 0;
}