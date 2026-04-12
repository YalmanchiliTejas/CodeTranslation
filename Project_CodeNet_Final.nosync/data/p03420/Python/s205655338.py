import sys

N, K = map(int, sys.stdin.readline().split())

if K == 0:
    print(N*N)
    sys.exit()

# b は K 以上
# a は b * c + K <= a < b * (c+1)
ans = 0
for i in range(1, N+1):
    # print(N // i, (i - K), max(N % i - K, 0))
    tmp = (N // i) * max(i - K, 0) + max(N % i + 1 - K, 0)
    ans += tmp

print(ans)