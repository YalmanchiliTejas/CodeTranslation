N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7

cum = [0 for _ in range(N)]
cum[0] = A[0]
for i in range(N - 1):
    cum[i + 1] = (cum[i] + A[i + 1]) % mod

ans = 0
for i in range(N - 1):
    ans += (A[i] * (cum[N - 1] - cum[i])) % mod
print(ans % mod)