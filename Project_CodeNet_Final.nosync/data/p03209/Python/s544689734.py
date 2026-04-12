N, X = map(int, input().split())

all, pate = [1], [1]
for i in range(N):
  all.append(all[i]*2 + 3)
  pate.append(pate[i]*2 + 1)

def f(N, X):
  if N == 0:
    return 1
  elif X == 1:
    return 0
  elif X <= 1 + all[N-1]:
    return f(N-1, X-1)
  elif X == 2 + all[N-1]:
    return 1 + pate[N-1]
  elif X < 3 + 2 * all[N-1]:
    return 1 + pate[N-1] + f(N-1, X-2-all[N-1])
  elif X == 3 + 2 * all[N-1]:
    return 2 * pate[N-1] + 1
print(f(N, X))