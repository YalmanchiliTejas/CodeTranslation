N,M = map(int, raw_input().split())
E = [[] for _ in range(N)]
for _ in range(M):
  a,b = map(int, raw_input().split())
  E[a-1] += [b-1]
  E[b-1] += [a-1]

def BT(p, c, V):
  if c==N-1:
    return 1
  V[p] = True
  ans = 0
  for e in E[p]:
    if not V[e]:
      ans += BT(e, c+1, V)
  V[p] = False
  return ans

print BT(0, 0, [False]*N)
