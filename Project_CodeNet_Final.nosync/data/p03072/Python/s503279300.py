n=int(input())
h=list(map(int,input().split()))
ans=1
for i in range(1,n):
  r=True
  for j in range(i):
    if h[i]<h[j]:
      r=False
  if r==True:
    ans+=1
print(ans)
  