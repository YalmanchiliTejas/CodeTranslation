n=int(input())
h=list(map(int,input().split()))
mxh=h[0]
ans=1
for i in range(1,n):
  if mxh <= h[i]:
    ans += 1
    mxh=h[i]
print(ans)