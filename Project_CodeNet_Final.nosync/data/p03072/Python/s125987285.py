n = int(input())
h = list(map(int, input().split()))
ans = 1
for i in range(1,n):
  c = 0
  for j in range(i):
    if h[i] >= h[j]:
      c += 1
  if c == i:
    ans += 1
print(ans)