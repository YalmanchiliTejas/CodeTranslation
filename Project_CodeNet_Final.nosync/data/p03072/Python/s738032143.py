n=int(input())
H=[int(i) for i in input().split()]

cnt=0
for i in range(n):
  flag=True
  for j in range(i):
    if H[j]>H[i]:
      flag=False
      break
  if flag:
    cnt+=1
print(cnt)
      