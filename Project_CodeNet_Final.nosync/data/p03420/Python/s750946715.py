def f(b, K, N):
    i = N // b
    ans = N - ((K-1) + (i - 1) * K + min((N%b) + 1, K))
    return ans

N, K = map(int, input().split(' '))
if K == 0:
    ans = int(N * N)
    print(ans)
else:
    ans = 0
    for b in range(K+1, N+1):
        ans += f(b, K, N)
    print(ans)