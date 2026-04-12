n=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(n):
  count=0
  for j in range(i+1):
    if h[i]>=h[j]:
      count+=1
  if count==i+1:
    ans+=1
print(ans)