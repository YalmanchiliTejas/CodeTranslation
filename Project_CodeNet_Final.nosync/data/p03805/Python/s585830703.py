N,M=map(int,input().split())
AB=[[] for _ in range(N)]
for _ in range(M):
  a,b=map(int,input().split())
  AB[a-1].append(b)
  AB[b-1].append(a)

def dfs(n,seen):
  global ans
  seen.append(n)
  if len(seen)==N:
    ans+=1
  else:
    for i in AB[n-1]:
      if i not in seen:
        dfs(i,seen)
  seen.remove(n)

ans=0
dfs(1,[])
print(ans)