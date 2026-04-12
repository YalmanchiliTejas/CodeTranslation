N, X = map(int, input().split())
a = [1]
p = [1]
for _ in range(N):
  a += [2*a[-1]+3]
  p += [2*p[-1]+1]

def fx(N, X):
  if N == 0:
    if X <= 0:
      return 0
    else:
      return 1
  elif X <= a[N-1]+1:
    return fx(N-1, X-1)
  else:
    return p[N-1]+1+fx(N-1, X-2-a[N-1])


print(fx(N, X))