n = int(input())
h = [int(i) for i in input().split()]

ans = 0
for i in range(n):
  tmp = 0
  for j in range(i):
    if h[j] <= h[i]:
      tmp += 1
  if tmp == i:
    ans += 1
print(ans)
