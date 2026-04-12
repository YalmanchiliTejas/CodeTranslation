n,m=map(int,input().split())
nexts=[None for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  a,b=a-1,b-1
  if nexts[a]==None:
    nexts[a]=[b]
  elif b not in nexts[a]:
    nexts[a].append(b)
  if nexts[b]==None:
    nexts[b]=[a]
  elif a not in nexts[b]:
    nexts[b].append(a)

ans=0
stack=[]
stack.append([0,[]])
while stack:
  node=stack.pop()
  v=node[0]
  seen=node[1][:]
  seen.append(v)
  if len(seen)==n:
    ans+=1
    continue
  childs=nexts[v]
  if childs:
    for child in (set(childs)-set(seen)):
      stack.append([child,seen])
  
print(ans)
