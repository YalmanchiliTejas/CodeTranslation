import itertools

n,m=map(int,input().split())
ans=0

graph=[[] for i in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

for lst in itertools.permutations([j for j in range(1,n)],n-1):
  now=0
  flag=True
  for i in range(n-1):
      if lst[i] not in graph[now]:
          flag=False
          break
      
      else:
          now=lst[i]

  if flag:
          ans+=1


print(ans)  