import sys
import itertools

input = sys.stdin.readline

N = int(input())
H = map(int, input().split())

highest = 0
ans = 0
for h in H:
  if h >= highest:
    ans += 1
    highest = h

print(ans)