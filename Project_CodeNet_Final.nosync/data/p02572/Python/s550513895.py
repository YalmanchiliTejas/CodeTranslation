N = int(input())
A = list(map(int, input().split()))

MOD = 1000000007

a = 0
b = 0
for i in range(N):
    a += A[i] % MOD
    b += (A[i] ** 2) % MOD
a = a ** 2
ans = (a - b) * pow(2, MOD - 2, MOD) % MOD
print(ans)