N,X,M=[int(s) for s in input().split()]
modls=[0 for _ in range(M+1)]
modls[0]=X
modset=set()
for i in range(1,M+1):
  k=(modls[i-1]**2)%M
  if k in modset:
    break
  modls[i]=k
  modset.add(k)
loop_end=i
loop_start=modls.index(k)
loop_length=loop_end-loop_start

ans=0
ans+=sum(modls[:loop_start])
if k!=0:
  ans+=sum(modls[loop_start:])*((N-loop_start)//loop_length)
  ans+=sum(modls[loop_start:loop_start  +  (N-loop_start)%loop_length])
print(ans)