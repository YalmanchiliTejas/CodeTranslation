import itertools
n,m=map(int,input().split())
link=[[]for j in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  link[a-1].append(b-1)
  link[b-1].append(a-1)
s=list(range(1,n))
res=0
for perm in list(itertools.permutations(s)):
  last=0
  ok=True
  for i in range(n-1):
    if perm[i] not in link[last]:
      ok=False
      break
    else:
      last=perm[i]
  if ok==True:
    res=res+1
print(res)