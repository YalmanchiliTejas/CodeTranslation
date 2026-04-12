n=int(input())
h=list(map(int,input().split()))
check=h[0]
ans=1
for i in range(1,n):
  if h[i]>=check:
    ans=ans+1
    check=h[i]
print(ans)
