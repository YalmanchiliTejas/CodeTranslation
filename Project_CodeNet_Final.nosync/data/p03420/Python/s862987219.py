N, K = map(int, input().split())
ans = 0
for b in range(1, N+1):
    p = N // b
    r = N % b
    ans += p * max(0, b - K)
    ans += max(0, r - K + 1)
if K == 0:
    ans -= N
print(ans)