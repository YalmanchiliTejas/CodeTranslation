n,m=map(int, input().split())
alist=[]
for i in range(m):
  a,b=map(int, input().split())
  alist.append([a,b])
  alist.append([b,a])
ans=0
import itertools
t=[i for i in range(1,n+1)]
blist=list(itertools.permutations(t,n))
ans=0
for i in blist:
  flag=True
  for j in range(n-1):
    if [i[j],i[j+1]] not in alist:
      flag=False
  if i[0]!=1:
      flag=False
  if flag:
    ans+=1
print(ans)