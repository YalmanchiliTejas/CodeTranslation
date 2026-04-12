import sys

N, K = map(int, raw_input().split())

if K == 0:
    print N * N
    sys.exit()

ans = 0
for i in range(K + 1, N+1):
    ans += max(N % i - K + 1, 0) + (N / i) * (i - K)


print ans
