N = int(input())
H = list(map(int,input().split()))
ans = 1
for i in range(1,N):
  flag = 0
  for j in range(i):
    if H[i]<H[j]:
      flag=1
  if flag == 0:
    ans+=1
print(ans)
