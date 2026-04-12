def solve():
  N = int(input())
  AA = list(map(int,input().split()))
 
  ans = 0
  for a in AA:
    ans += a
  ans = ans**2
  for a in AA:
    ans -= a**2
  ans = ans//2
  print(ans%(10**9+7))
solve()