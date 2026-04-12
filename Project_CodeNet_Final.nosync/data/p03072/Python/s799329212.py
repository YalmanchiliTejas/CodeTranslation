n = int(input())
h = list(map(int, input().split()))
ans = 1
for i in range(1, n):
  f = 0
  for j in range(i): 
    if f == 0:
      if h[j] <= h[i]:
        next
      else:
        f = 1
  if f == 0:
    ans += 1
print(ans)