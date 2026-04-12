from collections import deque

N = int(input())
A = list(map(int,input().split()))
allsum = 0
sums_list = deque()
sums = 0
for i in range(N-1, 0, -1):
  sums = (sums + A[i]) % (10**9 + 7)
  sums_list.appendleft(sums)
for i in range(N-1):
  allsum = (allsum + A[i] * sums_list[i]) % (10**9 + 7)
print(allsum)