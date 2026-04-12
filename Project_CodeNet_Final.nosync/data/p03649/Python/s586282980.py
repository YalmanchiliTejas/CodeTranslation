import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))

def check(x):
  b = a[: ]
  for i in range(N):
    b[i] += x
  c = 0
  for i in range(N):
    t = max(0, b[i] - (N - 1))
    c += -(-t // (N + 1))
  return c <= x

ok = sum(a)
ng = -1
while ok - ng > 1:
  m = (ok + ng) // 2
  isok = 0
  for i in range(N):
    if check(m + i):
      isok = 1
      break
  if isok: ok = m
  else: ng = m
for i in range(N):
  if check(ok + i):
    print(ok + i)
    break