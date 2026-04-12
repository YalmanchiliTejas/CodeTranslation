import sys
sys.setrecursionlimit(10**9)

N, X = map(int, input().split())

def num_p(n):
  return 2**(n+1) - 1

def num_layer(n):
  return 2**(n+2) - 3

def solve(n, x):
  if x <= 0:
    return 0
  num = num_layer(n-1) + 2
  if x == num*2 - 1:
    return num_p(n)
  elif x == num:
    return num_p(n-1) + 1
  elif x < num:
    return solve(n-1, x-1) # 1番下のバンを食べる
  else:
    return solve(n-1, x-num) + num_p(n-1) + 1

print(solve(N, X))