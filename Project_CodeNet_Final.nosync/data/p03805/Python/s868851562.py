N,M=map(int,input().split())
A=[list(map(int,input().split())) for _ in range(M)]
D=[[]for i in range(N)]
for u,v in A:
  D[u-1].append(v-1)
  D[v-1].append(u-1)

def dfs(x,used):
  if len(used)==N:
    return 1
  ans=0
  for i in D[x]:
    if i not in used:
      ans+=dfs(i,used+[i])
  return ans
print(dfs(0,[0]))  