import itertools
n,m=map(int,input().split())
edge =[[] for i in range(n+1)]
for i in range(m):
  a,b=map(int,input().split())
  edge[a].append(b)
  edge[b].append(a)

all_lis = list(itertools.permutations(list(range(2,n+1))))

def sati(x):
  #xはリスト[4,5,7]
  now=1
  for i in range(n-1):
    if not (x[i] in edge[now]):
      return 0
    now=x[i]
  return 1
ans=0
for i in all_lis:
  ans+=sati(i)
print(ans)