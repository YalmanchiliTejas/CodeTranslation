import itertools
n,m=map(int,input().split())
edge=[list(map(int,input().split())) for i in range(m)]
ans=0
nums=[i for i in range(1,n+1)]
rout=itertools.permutations(nums,n)
for r in rout:
  if r[0]!=1:
    continue
  lim=0
  while lim<n-1:
    if [r[lim],r[lim+1]] in edge or [r[lim+1],r[lim]] in edge:
      lim+=1
    else:
      lim=0
      break
  if lim:
    ans+=1
print(ans)