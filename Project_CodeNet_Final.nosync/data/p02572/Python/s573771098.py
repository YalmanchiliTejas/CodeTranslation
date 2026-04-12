
n = int(input())
A = list(map(int, input().split()))


mod = 10**9+7
s = sum(A)

ans = 0

for i in range(n):
    s -= A[i]
    ans += (A[i] * s) % mod

print(ans%mod)