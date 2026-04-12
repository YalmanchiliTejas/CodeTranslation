import math,itertools,fractions,heapq,collections,bisect,sys,queue,copy

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7
dd=[(-1,0),(0,1),(1,0),(0,-1)]
ddn=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
# def LF(): return [float(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return input()

N,M=LI()
graph=[[False]*8 for _ in range(8)]

for _ in range(M):
  a,b=LI()
  a-=1
  b-=1
  graph[a][b]=True
  graph[b][a]=True

def dfs(v,visited):
  all_visited=True
  for i in range(N):
    if not visited[i]:
      all_visited=False
  if all_visited:
    return 1

  ret=0
  for i in range(N):
    if not graph[v][i]:
      continue
    if visited[i]:
      continue
    visited[i]=True
    ret+=dfs(i,visited)
    visited[i]=False

  return ret

visited=[False]*N
visited[0]=True
print(dfs(0,visited))
