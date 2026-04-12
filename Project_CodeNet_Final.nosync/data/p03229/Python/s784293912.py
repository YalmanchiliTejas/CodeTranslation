import sys
from collections import deque as dq
input = sys.stdin.readline
N = int(input())
a = []
for _ in range(N):
  a.append(int(input()))
sa = dq(sorted(a))
res = 0
x = [0] * N
x[0] = sa[N // 2]
for i in range(1, N):
  if i % 2 == 0:
    x[i] = sa.popleft()
  else:
    x[i] = sa.pop()

for i in range(N - 1): res += abs(x[i + 1] - x[i])
res2 = 0
sa = dq(sorted(a))
x = [0] * N
x[0] = sa[-N // 2]
for i in range(1, N):
  if i % 2:
    x[i] = sa.popleft()
  else:
    x[i] = sa.pop()
for i in range(N - 1): res2 += abs(x[i + 1] - x[i])
print(max(res, res2))