n=int(input())
h=list(map(int,input().split()))

cnt=0
for i in range(1,n):
  flag=0
  for j in range(i):
    if h[i]>=h[j]:
      continue
    else:
      flag=1
      break
  if flag==0:
    cnt+=1
print(cnt+1)
