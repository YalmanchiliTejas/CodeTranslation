from functools import reduce
N, X, M = list(map(int, input().split()))

dp = [-1] * (M+1)

res = X
A = X
stream = []
spot = 0
for i in range(N-1)[1:]:
  stream.append(A)
  if dp[A] == -1:
    dp[A] = A**2 % M
  else:
    spot = i
    break
  res += dp[A]
  A = dp[A]

if N == 1:
  print(X)
elif spot == 0:
  res += A**2 % M
  print(res)
else:
  leftN = N - spot
  startRoopIndex = stream.index(A)
  roopSize = spot - stream.index(A) - 1
  roopScore = reduce(lambda res, a: res + dp[a], stream[startRoopIndex:spot-1], 0)
  res += (leftN // roopSize) * roopScore
  res += reduce(lambda res, a: res + dp[a], stream[startRoopIndex:(leftN % roopSize)+startRoopIndex], 0)
  print(res)