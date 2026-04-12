#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
  int n;
  std::vector< int > va;
  std::vector< int > vb;

  std::cin >> n;
  for (int i=0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    va.push_back(tmp);
  }

  vb.resize(n, 0);

  int sign = n % 2 == 0 ? 1 : -1;
  int idx = (int)(n/2);
  for (int i=0; i < n; i++) {
    idx += sign * i;
    vb[idx] = va[i];
    sign *= -1;
  }

  std::vector< int >::iterator it;
  for (it = vb.begin(); it != vb.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
