import sys
from bisect import bisect_right as br
input = sys.stdin.readline
N = int(input())
a = []
for _ in range(N): a.append(int(input()))
lis = [float("inf") for _ in range(N)]
reva = a[: : -1]

for i in range(N):
  j = br(lis, reva[i])
  lis[j] = reva[i]

res = N
for i in range(N):
  if lis[i] == float("inf"):
    res = i
    break
print(res)