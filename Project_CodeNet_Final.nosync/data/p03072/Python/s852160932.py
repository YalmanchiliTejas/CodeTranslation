N=int(input())

RYO=list(map(int,input().split()))
height=0
ans=0
for i in range(N):
  if RYO[i]>=height:
    ans+=1
    height=RYO[i]
print(ans)