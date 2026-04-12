N, X = map(int, input().split())
a = [1]
b = [1]
for i in range(N):
  a.append(2*a[i] + 3)
  b.append(2*b[i] + 1)

def F(N, X):
  if N == 0:
    if X > 0:
      return 1
    else:
      return 0

  if X == 1:
    return 0

  if 1 < X <= a[N-1] + 1:
    return F(N-1, X-1)

  if X ==  a[N-1] + 2:
    return b[N-1] + 1

  if a[N-1] + 2 < X <= 2*a[N-1] + 2:
    return b[N-1] + 1 + F(N-1, X - 2 - a[N-1])

  if X == 2 * a[N-1] + 3:
    return 2 * b[N-1] + 1

print(F(N, X))
