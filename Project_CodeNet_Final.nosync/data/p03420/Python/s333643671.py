N, K = map(int, input().split())

ans = 0
if K == 0:
    ans = N * N
else:
    for i in range(K+1, N+1):
        hoge = N // i
        ans += (i - K) * hoge
        fuga = N % i
        ans += max(0, fuga-K+1)

print(ans)
