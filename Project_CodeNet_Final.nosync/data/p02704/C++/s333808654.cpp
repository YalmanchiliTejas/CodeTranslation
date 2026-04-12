
#include <iostream>
#include <cstdint>
#include <vector>

using u16 = uint16_t;
using u64 = uint64_t;

int main() {
  size_t N;
  std::cin >> N;
  std::vector<u16> S(N), T(N);
  std::vector<u64> U(N), V(N);
  for (auto &x: S) {
    std::cin >> x;
  }
  for (auto &x: T) {
    std::cin >> x;
  }
  for (auto &x: U) {
    std::cin >> x;
  }
  for (auto &x: V) {
    std::cin >> x;
  }
  if (N == 1) {
    if (U[0] == V[0]) {
      std::cout << U[0] << '\n';
    }
    else {
      std::cout << "-1\n";
    }
    return 0;
  }
  std::vector<std::vector<u64>> answer(N, std::vector<u64>(N));
  for (u16 digit = 0; digit < 64; ++digit) {
    u64 bit = u64(1) << digit;
    std::vector<u16> R(N), C(N);
    u16 state_r = 0, state_c = 0;
    for (size_t k = 0; k < N; ++k) {
      R[k] = U[k] >> digit & 1;
      C[k] = V[k] >> digit & 1;
      if (S[k] == 0 && R[k] == 1) {
        state_r |= 1;
      }
      if (S[k] == 1 && R[k] == 0) { 
        state_r |= 2;
      }
      if (T[k] == 0 && C[k] == 1) {
        state_c |= 1;
      }
      if (T[k] == 1 && C[k] == 0) {
        state_c |= 2;
      }
    }
    if (state_r == 0 && state_c == 0) {
      for (size_t i = 0; i < N; ++i) {
        answer[i][i] |= bit;
      }
    }
    else if (state_r == 0) {
      if (state_c == 1) {
        size_t cnt = 0;
        for (size_t j = 0; j < N; ++j) {
          if (T[j] == 0 && C[j] == 1) {
            for (size_t i = 0; i < N; ++i) {
              answer[i][j] |= bit;
            }
          }
          else {
            ++cnt;
          }
        }
        if (cnt >= 2) {
          size_t cur = 0;
          for (size_t j = 0; j < N; ++j) {
            if (T[j] != 0 || C[j] != 1) {
              answer[cur][j] |= bit;
              ++cur;
            }
          }
        }
        else if (cnt == 1) {
          size_t j;
          for (j = 0; j < N; ++j) {
            if (T[j] != 0 || C[j] != 1) {
              break;
            }
          }
          for (size_t i = 0; i < N; ++i) {
            if (S[i] == 1) {
              answer[i][j] |= bit;
              break;
            }
          }
        }
      }
      else if (state_c == 2) {
        size_t cnt = 0;
        for (size_t j = 0; j < N; ++j) {
          if (T[j] != 1 || C[j] != 0) {
            for (size_t i = 0; i < N; ++i) {
              answer[i][j] |= bit;
            }
            ++cnt;
          }
        }
        if (cnt >= 2) {
          size_t cur = 0;
          for (size_t j = 0; j < N; ++j) {
            if (T[j] != 1 || C[j] != 0) {
              answer[cur][j] &= ~bit;
              ++cur;
            }
          }
        }
        else if (cnt == 1) {
          size_t j;
          for (j = 0; j < N; ++j) {
            if (T[j] != 1 || C[j] != 0) {
              break;
            }
          }
          for (size_t i = 0; i < N; ++i) {
            if (S[i] == 0) {
              answer[i][j] &= ~bit;
              break;
            }
          }
        }
      }
      else {
        for (size_t j = 0; j < N; ++j) {
          answer[0][j] |= bit;
          if (T[j] == 0 && C[j] == 1) {
            for (size_t i = 0; i < N; ++i) {
              answer[i][j] |= bit;
            }
          }
          if (T[j] == 1 && C[j] == 0) {
            answer[0][j] &= ~bit;
          }
        }
      }
    }
    else if (state_c == 0) {
      if (state_r == 1) {
        size_t cnt = 0;
        for (size_t i = 0; i < N; ++i) {
          if (S[i] == 0 && R[i] == 1) {
            for (size_t j = 0; j < N; ++j) {
              answer[i][j] |= bit;
            }
          }
          else {
            ++cnt;
          }
        }
        if (cnt >= 2) {
          size_t cur = 0;
          for (size_t i = 0; i < N; ++i) {
            if (S[i] != 0 || R[i] != 1) {
              answer[i][cur] |= bit;
              ++cur;
            }
          }
        }
        else if (cnt == 1) {
          size_t i;
          for (i = 0; i < N; ++i) {
            if (S[i] != 0 || R[i] != 1) {
              break;
            }
          }
          for (size_t j = 0; j < N; ++j) {
            if (T[j] == 1) {
              answer[i][j] |= bit;
              break;
            }
          }
        }
      }
      else if (state_r == 2) {
        size_t cnt = 0;
        for (size_t i = 0; i < N; ++i) {
          if (S[i] != 1 || R[i] != 0) {
            for (size_t j = 0; j < N; ++j) {
              answer[i][j] |= bit;
            }
            ++cnt;
          }
        }
        if (cnt >= 2) {
          size_t cur = 0;
          for (size_t i = 0; i < N; ++i) {
            if (S[i] != 1 || R[i] != 0) {
              answer[i][cur] &= ~bit;
              ++cur;
            }
          }
        }
        else if (cnt == 1) {
          size_t i;
          for (i = 0; i < N; ++i) {
            if (S[i] != 1 || R[i] != 0) {
              break;
            }
          }
          for (size_t j = 0; j < N; ++j) {
            if (T[j] == 0) {
              answer[i][j] &= ~bit;
              break;
            }
          }
        }
      }
      else {
        for (size_t i = 0; i < N; ++i) {
          answer[i][0] |= bit;
          if (S[i] == 0 && R[i] == 1) {
            for (size_t j = 0; j < N; ++j) {
              answer[i][j] |= bit;
            }
          }
          if (S[i] == 1 && R[i] == 0) {
            answer[i][0] &= ~bit;
          }
        }
      }
    }
    else {
      u16 state = state_r | state_c;
      if (state == 3) {
        std::cout << "-1\n";
        return 0;
      }
      if (state == 1) {
        for (size_t i = 0; i < N; ++i) {
          for (size_t j = 0; j < N; ++j) {
            answer[i][j] &= ~bit;
            if (S[i] == 0 && R[i] == 1) {
              answer[i][j] |= bit;
            }
            if (T[j] == 0 && C[j] == 1) {
              answer[i][j] |= bit;
            }
          }
        }
      }
      else {
        for (size_t i = 0; i < N; ++i) {
          for (size_t j = 0; j < N; ++j) {
            answer[i][j] |= bit;
            if (S[i] == 1 && R[i] == 0) {
              answer[i][j] &= ~bit;
            }
            if (T[j] == 1 && C[j] == 0) {
              answer[i][j] &= ~bit;
            }
          }
        }
      }
    }
  }
  for (size_t i = 0; i < N; ++i) {
    if (S[i] == 0) {
      u64 cur = ~u64(0);
      for (size_t j = 0; j < N; ++j) {
        cur &= answer[i][j];
      }
      if (cur != U[i]) {
        std::cout << "-1\n";
        return 0;
      }
    }
    else {
      u64 cur = 0;
      for (size_t j = 0; j < N; ++j) {
        cur |= answer[i][j];
      }
      if (cur != U[i]) {
        std::cout << "-1\n";
        return 0;
      }
    }
  }
  for (size_t j = 0; j < N; ++j) {
    if (T[j] == 0) {
      u64 cur = ~u64(0);
      for (size_t i = 0; i < N; ++i) {
        cur &= answer[i][j];
      }
      if (cur != V[j]) {
        std::cout << "-1\n";
        return 0;
      }
    }
    else {
      u64 cur = 0;
      for (size_t i = 0; i < N; ++i) {
        cur |= answer[i][j];
      }
      if (cur != V[j]) {
        std::cout << "-1\n";
        return 0;
      }
    }
  }
  for (const auto &vec: answer) {
    for (size_t i = 0; i < N; ++i) {
      std::cout << vec[i];
      std::cout << (i + 1 == N ? '\n' : ' ');
    }
  }
  return 0;
}
