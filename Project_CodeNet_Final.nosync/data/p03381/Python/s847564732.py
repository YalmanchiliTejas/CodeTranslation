N = int(input())
X = list(map(int, input().split()))

Y = sorted(X)
m = Y[N//2 - 1]
M = Y[N//2]

for x in X:
  if m == M:
    print(m)
  elif x <= m:
    print(M)
  else:
    print(m)