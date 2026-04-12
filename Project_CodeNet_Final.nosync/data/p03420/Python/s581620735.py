
N, K = map(int, input().split())

ans = 0

i = K + 1

if K == 0:
    ans = N * N
else:
    while i <= N:
        div = N // i
        ans += max(N % i - K + 1, 0)
        ans += div * (i - K)
        i += 1


print(ans)

