n,m=map(int,input().split())
edge=[list(map(int,input().split())) for i in range(m)]
ans=0
rout=[[0 for i in range(n)]]
rout[0][0]=1
for i in range(2,n+1):
  rout2=[]
  for j in range(len(rout)):
    for k in range(n):
      if rout[j][k]==0:
        r=rout[j][:]
        r[k]=i
        rout2.append(r)
  rout=rout2
for r in rout:
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