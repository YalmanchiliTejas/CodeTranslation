import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
sa = sorted(a)
l = sa[N // 2 - 1]
r = sa[N // 2]
for i in range(N):
  if a[i] <= l: print(r)
  else: print(l)