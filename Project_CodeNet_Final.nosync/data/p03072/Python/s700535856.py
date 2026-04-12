n = int(input())
h = list(map(int,input().split()))
ans = 0
for i in range(n):
  ok = True
  for j in range(i):
    if h[j]<=h[i]:
      continue
    else:
      ok = False
      break
  if(ok):
    ans+=1
print(ans)
  