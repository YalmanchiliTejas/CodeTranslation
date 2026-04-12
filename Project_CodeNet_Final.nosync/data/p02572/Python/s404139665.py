N = int(input())

A = list(map(int, input().split()))

MOD = 1000000007
s = sum(A)

ans = 0

for i in range(N):
    s -= A[i]
    ans += A[i] * s

print(ans % MOD)
