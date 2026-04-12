n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
  f=True
  for j in range(i):
    if a[j] >a[i]:
      f=False
  if f:
    ans+=1
print(ans)