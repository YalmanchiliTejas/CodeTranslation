import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
a.sort()
def check(x):
  b = [0] * N
  for i in range(N):
    b[i] = a[i] + x
  t = x
  for i in range(N):
    if t * (N + 1) >= b[i] - (N - 1):
      t -= -(-(b[i] - (N - 1)) // (N + 1))
    else:
      return False
  return True


ok = sum(a)
ng = -1

while ok - ng > 1:
  m = (ok + ng) // 2
  isok = 0
  for i in range(50):
    if check(m + i):
      isok = 1
      break
  if isok: ok = m
  else: ng = m


for i in range(50):
  if check(ok + i):
    print(ok + i)
    break