def solve():
  N = int(input())
  H = [int(i) for i in input().split()]
  cnt = 0
  highest = 0
  for h in H:
    if h >= highest:
      cnt = cnt + 1
      highest = h
  return cnt

print(solve())