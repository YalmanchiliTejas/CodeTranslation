import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
res = 0
for d in range(1, N):
  s = set()
  t = 0
  for k in range(N):
    i = d * k
    if i + d >= N: break
    if i in s: break
    if N - 1 - i in s: break
    if i == N - 1 - i: break
    s.add(i)
    s.add(N - 1 - i)
    t += a[i]
    t += a[N - 1 - i]
    res = max(res, t)
print(res)
