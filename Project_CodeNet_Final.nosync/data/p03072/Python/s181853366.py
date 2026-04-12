N = int(input())
H = list(map(int,input().split()))
ans = 0
for i in range(len(H)):
  if i ==0 :
    ans += 1
  else :
    isOK = 0
    for j in range(i):
      if H[j] > H[i]:
        isOK += 1
    if isOK == 0:
      ans += 1

print(ans)
    