import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
if max(a) < N:
  print(0)
  exit(0)
ng = 0
ok = max(a) * N
def check(x):
  c = 0
  for i in range(N):
    c += max(-(-(a[i] + x - N + 1) // (N + 1)), 0)
  return x >= c

while ok - ng > 1:
  m = (ok + ng) // 2
  f = 1
  for i in range(N):
    if check(m + i):
      ok = m
      f = 0
      break
  if f: ng = m
for i in range(N):
  if check(ok + i):
    print(ok + i)
    break