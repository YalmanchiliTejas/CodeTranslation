n= int(input())
h = list(map(int,input().split()))
ans = 0
for i in range(n):
  cnt = 0
  for j in range(i):
    if h[j] <= h[i]:
      cnt += 1
    else:
      pass
  if cnt == i:
    ans += 1
print(ans)