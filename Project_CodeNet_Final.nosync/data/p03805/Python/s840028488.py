import itertools
n,m = map(int,input().split())
e = [[False]*n for _ in range(n)]
for _ in range(m):
  a,b = map(int,input().split())
  e[a-1][b-1] = True
  e[b-1][a-1] = True

ans = 0
l = [i for i in range(1,n)]
for p in itertools.permutations(l):
  p = [0] + list(p)
  reach = 1
  for i in range(n-1):
    if not e[p[i]][p[i+1]]:
      reach = 0
      break
  ans += reach

print(ans)