n = int(input())
h = list(map(int, input().split()))

ans = 1
if len(h) >= 2:
  if h[0] <= h[1]:
    ans += 1
  for i in range(2,n):
    isCount = True
    if h[0] <= h[i]:
      if h[1] <= h[i]:
      	for j in range(1,i):
          if h[j] > h[i]:
          	isCount = False
      	if isCount:
          ans += 1
print(ans)