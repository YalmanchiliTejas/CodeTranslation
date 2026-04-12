n,m=map(int,input().split())
l=[[] for i in range(n+1)]
for i in range(m):
  a,b=map(int,input().split())
  l[a].append(b)
  l[b].append(a)
lans=[]
def dfs(i,l1):
  if len(l1)==n:
    lans.append(l1)
    return
  for j in l[i]:
    if j in l1:
      pass
    else:
      l2=l1+[j]
      dfs(j,l2)
  return
dfs(1,[1])
print(len(lans))