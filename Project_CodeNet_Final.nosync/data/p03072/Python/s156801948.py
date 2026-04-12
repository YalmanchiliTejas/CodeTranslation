N = int(input())
n = list(map(int, input().split()))
c = 1
for i in range(1, N):
  for j in range(i):
    if n[j] > n[i]:
      break
    if j == i - 1:
      c += 1
print(c)