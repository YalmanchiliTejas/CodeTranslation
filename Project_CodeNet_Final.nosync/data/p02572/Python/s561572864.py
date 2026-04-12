N = int(input())
A = list(map(int, input().split()))
s = sum(A)
ans = 0
MOD = 10**9+7
for i in range(N):
    s -= A[i]
    ans += s*A[i] % MOD
    ans %= MOD
print(ans)
