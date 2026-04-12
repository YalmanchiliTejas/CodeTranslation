N, K = map(int, input().split())

if K == 0:
    print(N ** 2)
    exit()

count = 0
for bi in range(K+1, N+1):
    count += (bi - K) * (N // bi) + max(0, N % bi - K + 1)
print(count)