N = int(input())
H = list(map(int, input().split()))
ans = 1
for i in range(1, N):
  isOK = True
  for j in range(i):
    if H[j] > H[i]:
      isOK = False
      break
  if isOK: ans+=1
print(ans)