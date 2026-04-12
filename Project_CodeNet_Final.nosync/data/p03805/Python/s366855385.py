n,m=[int(x) for x in input().rstrip().split()]
l=[[]*n for i in range(n)]
done=[False for i in range(n)]
for i in range(m):
  a,b=[int(x) for x in input().rstrip().split()]
  l[a-1].append(b-1)
  l[b-1].append(a-1)


def bfs():
  stack=[[0,[]]]
  ans=0
  while(stack):
    now,visited=stack.pop(0)
    if len(visited)==n-1:
      ans+=1    
    for i in l[now]:
      if i not in visited:
        stack.append([i,visited+[now]])
  return ans

print(bfs())