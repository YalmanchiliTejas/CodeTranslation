n=int(input())
hmax=0
ans=0
for h in map(int,input().split()):
  if hmax<=h:
    ans+=1
    hmax=h
print(ans)