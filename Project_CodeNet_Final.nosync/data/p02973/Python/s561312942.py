import sys
input = sys.stdin.readline
import bisect

N = int(input())
A = [-int(input()) for _ in range(N)]

Color = []
for a in A:
  idx = bisect.bisect_right(Color,a)
  if idx == len(Color):
    Color.append(a)
  else:
    Color[idx] = a
  #Color.sort()
  #print(Color)
print(len(Color))