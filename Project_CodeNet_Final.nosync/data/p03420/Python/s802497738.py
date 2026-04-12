import sys

N, K = map(int, input().split())
if K == 0:
    print(N*N)
    sys.exit()

ans = 0
for b in range(K, N+1):
    s, r = N//b, N % b
    ans += s * (b-K)
    ans += max(0, r - K + 1)
print(ans)
