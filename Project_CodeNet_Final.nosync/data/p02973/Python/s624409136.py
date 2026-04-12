import bisect
n = int(input())
A = [int(input()) for _ in range(n)]
L = [-1]*n
count = 0
for i in A:
  t = bisect.bisect_left(L, i) - 1
  if L[t] == -1:
    count += 1
  L[t] = i
print(count)