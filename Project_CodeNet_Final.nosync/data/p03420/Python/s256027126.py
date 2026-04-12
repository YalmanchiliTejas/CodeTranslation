N, K = map(int, input().split())

ans = 0

if K == 0:
  ans = N ** 2
else:
  for b in range(1, N + 1):
    p, r = divmod(N, b)
    ans += p * max(0, b - K) + max(0, r - K + 1)
print(ans)