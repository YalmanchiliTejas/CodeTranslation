n=int(input())
l=list(map(int,input().split()))
ans=1
for i in range(1,n):
  c=0
  for j in range(0,i):
    if l[i]<l[j]:
      c=1
      break
  if c==0:
    ans+=1
print(ans)
