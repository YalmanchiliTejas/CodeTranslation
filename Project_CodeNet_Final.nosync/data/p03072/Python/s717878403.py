N = int(input())
A = list(map(int, input().split()))
res = 0
for i in range(N):
  for j in range(i):
    if A[i] < A[j]:
      res -= 1
      break
  res += 1
print(res)