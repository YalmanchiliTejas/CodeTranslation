#include <iostream>
#include <vector>
#include <string>

using ll = long long;

void print(){ std::cout << std::endl; }
template< typename H > void print(H head){std::cout << head << std::endl;}
template< typename H, typename... T > void print(H head, T... tail) {std::cout << head << " ", print(tail...); }

int main()
{
  ll N, M;
  std::cin >> N >> M;

  bool judge = N == M;
  if (judge) print("Yes");
  else print("No");

  return 0;
}
