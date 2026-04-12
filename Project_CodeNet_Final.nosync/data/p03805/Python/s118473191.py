from itertools import permutations
n,m=map(int,input().split())
side=[[] for _ in range(n+1)]
for i in range(m):
  a,b=map(int,input().split())
  side[a].append(b)
  side[b].append(a)
route=[i for i in range(2,n+1)]
ans=0
for x in permutations(route):
  x=list(x)
  x.insert(0,1)
  for i in range(n-1):
    if x[i+1] not in side[x[i]]:
      break
  else:
    ans+=1
print(ans)