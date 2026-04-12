N = int(input())

A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

x = 0
ans = 0
for i in range(len(A)):
    ans += A[i] * x % MOD
    x += A[i] % MOD
print(ans%MOD)    