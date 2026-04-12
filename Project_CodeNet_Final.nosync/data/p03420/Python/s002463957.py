N, K = map(int, input().split())

if K == 0:
  print(N**2)
  exit()

ans = 0
for b in range(1, N+1):
  if b <= K:
    continue
  ans += (N // b) * (b - K)
  ans += max(0, N % b - K + 1)

print(ans)