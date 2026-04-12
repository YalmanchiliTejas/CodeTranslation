N, K = map(int, input().split())
c = 1
ans = 0
if K == 0:
    print(N*N)
else:
    for i in range(K+1, N+1):
        ans += c*(N // i)
        ans += max(N % i - K + 1, 0)
        c += 1
    print(ans)