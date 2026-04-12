import sys
input = sys.stdin.readline
from bisect import bisect_right

N = int(input())
l = [-int(input())]

for i in range(N-1):
  ai = -int(input())
# 各色の最大値がlの要素になるようにリストを拡大させていく
  if l[-1] <= ai:
    l.append(ai)
  else:
    b = bisect_right(l, ai)
    l[b] = ai
    
print(len(l))