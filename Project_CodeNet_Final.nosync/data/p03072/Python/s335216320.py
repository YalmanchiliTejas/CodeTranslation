n=int(input())
lists=list(map(int,input().split()))
a=0
ans=0
for i in range (0,n):
  if lists[i]>=a:
    a=lists[i]
    ans=ans+1
print(ans)