n=int(input())
h=list(map(int,input().split()))
maxh=0
ans=0
for i in range(n):
  if maxh<=h[i]:
    ans+=1
    maxh=max(maxh,h[i])
print(ans)