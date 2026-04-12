import sys
sys.setrecursionlimit(10 ** 6)

from math import factorial
def comb(n, r):
  if r < 0 or r > n:
    return 0
  else:
    return factorial(n) // (factorial(n - r) * factorial(r))

# 左から i 桁目以降について、0 以外の値を残り K 個使用可能
# smaller: i 桁目までが 一致している時=False, 小さい時=True  
def solve(i, k, smaller):
  if i == n:
    if k == 0:
      return 1
    else:
      return 0
  if k == 0:
    return 1
  if smaller:
    return comb(n - i, k) * 9 ** k
  else:
    if S[i] == "0":
      return solve(i + 1, k, False)
    else:
      zero = solve(i + 1, k, True)
      aida = solve(i + 1, k - 1, True) * (int(S[i]) - 1)
      icchi = solve(i + 1, k - 1, False)
      return zero + aida + icchi

S = input()  
n = len(S)
k = int(input())
print(solve(0, k, False))