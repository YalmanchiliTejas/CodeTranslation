N, K = map(int, input().split())

result = 0
if K == 0:
    result = N * N
else:
    for i in range(K+1, N+1):
        result += (N//i * (i - K) + max(N%i-K+1, 0))

print(result)
