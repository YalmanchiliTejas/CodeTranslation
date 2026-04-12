N,M = map(int,input().split())
G = dict([(i,[]) for i in range(1,N+1)])
for i in range(M):
  a,b = map(int,input().split())
  G[a].append(b)
  G[b].append(a)
#深さ優先探索  
l = [0]
def dfs(p,s):
  for i in G[p]:
    if s[i] == "0":
      a = s[:i] + "1" + s[i+1:]
      dfs(i,a)
  if s == "0" + N*"1":
    l[0] += 1
#捜査
s = "01"+(N-1)*"0"
    
dfs(1,s)
print(l[0])