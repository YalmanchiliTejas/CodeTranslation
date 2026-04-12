N = int(input())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

B = [0] * (N + 1)
for i in range(N):
    B[i + 1] = (B[i] + A[i]) % MOD

ans = 0
tmp = B[-1]
for i in range(N):
    ans += (A[i] * (tmp - B[i + 1])) % MOD
    ans %= MOD

print (ans)