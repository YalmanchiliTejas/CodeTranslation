#include <iostream>
#include <cassert>

int count(const std::string& N, int pos, int k) {
  if (k == 0) {
    return 1;
  }
  int n = N.size() - pos;
  if (n < k) {
    return 0;
  }
  int head = N[pos] - '0';
  if (n == 1) {
    return head;
  }
  int combination1 = 0;
  int combination2 = 0;
  int combination3 = 0;
  if (head > 0) {
    combination1 = head - 1;
    if (k == 2) {
      combination1 *= (n - 1) * 9;
    } else if (k == 3) {
      combination1 *= (n - 1) * (n - 2) / 2 * 9 * 9;
    }
    combination2 = (n - 1) * 9;
    if (k >= 2) {
      combination2 = combination2 * (n - 2) / 2 * 9;
    }
    if (k >= 3) {
      combination2 = combination2 * (n - 3) / 3 * 9;
    }
    combination3 = count(N, pos + 1, k - 1);
  } else {
    combination3 = count(N, pos + 1, k);
  }
  return combination1 + combination2 + combination3;
}

int main() {
  std::string N;
  int k;
  std::cin >> N;
  std::cin >> k;
  std::cout << count(N, 0, k) << std::endl;

  return 0;
}
