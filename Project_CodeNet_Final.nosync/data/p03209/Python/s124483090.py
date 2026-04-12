import sys
sys.setrecursionlimit(10**5)

def solve(n, x):
  if n == 0:
    if x > 0:
      return 1
    else:
      return 0
  else:
    ans = 0
    burger_prev = 2**(n+1)-3
    pate_prev = 2**n-1
    if x > 1:
      if x < burger_prev+1:
        ans += solve(n-1 ,x-1)
      else:
        ans += pate_prev
        if x > burger_prev+1:
          ans += 1
          if x > burger_prev*2+2:
            ans += pate_prev
          else:
            ans += solve(n-1, x-2-burger_prev)
    return ans

N, X = map(int, input().split())
print(solve(N, X))
