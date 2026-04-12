mod = 10**9 + 7


N = int(input())
A = list(map(int, input().split()))

cumsum = A[:]
for i in range(N - 1)[::-1]:
    cumsum[i] += cumsum[i + 1]
    cumsum[i] %= mod

ans = 0
for i in range(N - 1):
    ans += A[i] * cumsum[i + 1]
    ans %= mod

print(ans)
