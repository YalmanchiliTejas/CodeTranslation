N = int(input())
L = list(map(int,input().split()))
L.insert(0,0)
ans = 0
for i in range(1,N+1):
  k = L[i]
  flag = True
  for j in range(i):
    if k >= L[j]:
      None
    else:
      flag = False
      break
  if flag:
    ans += 1
print(ans)