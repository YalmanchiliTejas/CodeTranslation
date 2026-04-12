x=int(input())
a=list(map(int,input().split()))
ans=0
mdd=-(10**18)
for i in a:
  if i>=mdd:
    mdd=i
    ans+=1
print(ans)