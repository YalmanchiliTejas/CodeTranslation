n=int(input())
h=list(map(int,input().split()))
x=h[0]
ans=1
for i in range(1,n):
  if h[i]>=x:
    x=h[i]
    ans+=1
print(ans)