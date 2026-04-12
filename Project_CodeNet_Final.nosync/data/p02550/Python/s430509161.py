N, X, M = list(map(int, input().split()))

L = [0] * M
S = [0] * (M + 1)
cnt = 1

L[X] = 1
S[1] = X

t = X
cnt = 1
for i in range(N):
  t = t * t % M
  if L[t] != 0:
    r = L[t]
    break
  L[t] = i + 2
  S[cnt + 1] = S[cnt] + t
  cnt += 1

if N <= cnt:
  print(S[N])
  exit()

roop = cnt - r + 1
d, m = divmod(N - r + 1, roop)

ans = (S[cnt] - S[r - 1]) * d
ans += S[r + m - 1]
print(ans)
