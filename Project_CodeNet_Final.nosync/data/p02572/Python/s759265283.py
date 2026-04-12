n = int(input())
a = list(map(int, input().split()))

A = [0]
for i in range(n):
    A.append(A[i] + a[i])

MOD = 10**9+7
ans = 0
for i in range(n-1):
    ans += (a[i] * (A[-1]-A[i+1])) % MOD

print(ans%MOD)