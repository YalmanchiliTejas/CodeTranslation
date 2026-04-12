N, X = map(int, input().split())
S = 0
M = 2 ** (N + 2) - 3
P = 2 ** (N + 1) - 1
for i in range(N+1):
  P -= 1
  P //= 2
  M -= 1
  M //= 2
  if X - 1 == 0:
    if M != 0:
      break
    else:
      S += 1
      break
  if X - 1 == M:
    S += 1 + P
    break
  elif X - 1 == 2 * M:
    S += 1 + 2 * P
    break
  elif (X - 1) % M != 0 and (X - 1) > M:
    S += 1 + P
    X -= M + 1
    M -= 1
  elif (X - 1) % M != 0 and (X - 1) < M:
    X -= 1
    M -= 1
print(S)