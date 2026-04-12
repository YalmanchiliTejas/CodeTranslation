N=int(input())
H=map(int,input().split())
ans,maxh=0,0
for h in H:
  if maxh<=h:
    ans+=1
    maxh=h
print(ans)