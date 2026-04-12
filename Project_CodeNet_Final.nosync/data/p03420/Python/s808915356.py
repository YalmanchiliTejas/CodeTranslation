import sys

N, K = map(int, sys.stdin.readline().split())

if K == 0:
    print(N*N)
    sys.exit()

ans = 0
for b in range(K+1, N+1):
    r = N // b
    # tmp = (b - K) * r
    # tmp2 = (N % b + 1 - K)
    # print(b, tmp, tmp2)
    tmp = (b - K) * r + max(0, N % b + 1 - K)
    ans += tmp

print(ans)