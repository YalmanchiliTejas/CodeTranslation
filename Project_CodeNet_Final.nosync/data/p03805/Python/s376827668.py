import sys
n,m=map(int,input().split())
number=[[int(i) for i in l.split()] for l in sys.stdin]
visit=[0]*(n+1)
visit[1]=1
node=[[] for i in range(n+1)]
for i in number:
  node[i[0]].append(i[1])
  node[i[1]].append(i[0])
ans=0
def dfs(x):
  global ans
  if visit.count(1)==n:
    ans+=1
    return 0
  for i in node[x]:
    if visit[i]==0:
      visit[i]=1
      dfs(i)
      visit[i]=0
  return 0
dfs(1)
print(ans)