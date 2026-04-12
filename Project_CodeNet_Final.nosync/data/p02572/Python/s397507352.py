import sys

def solve():
      input = sys.stdin.readline
      N = int(input())
      A = [int(a) for a in input().split()]
      sumA = 0
      mod = 7 + 10 ** 9
      for a in A:
            sumA += a
            sumA %= mod
      ans = 0
      for a in A:
            ans += ((sumA - a + mod) * a) % mod
            ans %= mod
      print((ans * pow(2, mod-2, mod)) % mod)

      return 0

if __name__ == "__main__":
      solve()