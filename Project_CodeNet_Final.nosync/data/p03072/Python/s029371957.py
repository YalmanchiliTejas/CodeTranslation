n=int(input())
h=list(map(int,input().split()))
mh=h[0]
ans=1
for i in range(1,n):
  if h[i]>=mh:
    ans+=1
    mh=h[i]
print(ans)