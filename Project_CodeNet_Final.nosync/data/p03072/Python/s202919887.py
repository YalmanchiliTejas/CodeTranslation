def solve():
  n = int(input())
  h = list(int(i) for i in input().split())
  ans = 1
  tp = h[0]
  for i in range(n-1):
    if tp <= h[i+1]:
      ans += 1
      tp = max(tp,h[i+1])
    else:
      continue
  print(ans)
solve()