from bisect import bisect_right as br
N = int(input())
inf = 10 ** 9 + 1
lis = [inf] * (N + 1)
res = 0
for _ in range(N):
  a = -int(input())
  ind = br(lis, a)
  if a <= lis[ind]:
    lis[ind] = a

for i in range(1, N + 1):
  if lis[i] == inf:
    break
  res = i
print(res + 1)