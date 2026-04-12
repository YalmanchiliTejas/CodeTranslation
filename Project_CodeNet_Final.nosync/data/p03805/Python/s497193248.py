def dfs(v,children,checked):
  if len(checked)==len(children):
    return 1
  ans = 0
  for child in children[v]:
    if child in checked:
      continue
    ncheck = set(checked)
    ncheck.add(child)
    ans += dfs(child,children,ncheck)
  return ans

n,m = tuple(map(int,input().split()))

children = [[]for _ in range(n)]
for i in range(m):
  a,b = tuple(map(int,input().split()))
  children[a-1].append(b-1)
  children[b-1].append(a-1)

ans = dfs(0,children,set([0]))

print(ans)
  
