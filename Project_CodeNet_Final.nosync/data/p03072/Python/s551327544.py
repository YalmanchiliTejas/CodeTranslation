N=int(input())
H=[0]+[int(x) for x in input().split()]
s=0
ans=0
for i in range(1,N+1):
  if H[i]>=H[s]:
    ans+=1
    s=i
print(ans)