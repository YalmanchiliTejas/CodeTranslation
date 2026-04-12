N, M = [int(x) for x in input().split()]
P = [[False] * N for m in range(N)]
dict={}
for m in range(M):
  a, b = [int(x) for x in input().split()]
  P[a-1][b-1] = True
  P[b-1][a-1] = True

def dp(x, past):
  past[x] = True
  if (x, tuple(past)) in dict:
    return dict[(x, tuple(past))]
  if False not in past:
    return 1
  ret = 0
  for i,p in enumerate(P[x]):
    if not p or x == i or past[i]:
      continue
    else:
      ret += dp(i, past[:])
  dict[(x, tuple(past))] = ret
  return ret

if M < N - 1:
  print(0)
else:
  print(dp(0, [False] * N))