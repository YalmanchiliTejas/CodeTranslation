mod = 10**9+7

N = int(input())
A = list(map(int, input().split()))

s = 0
for i in range(N):
    s += A[i]
ans = 0
for i in range(N):
    ans += (A[i]*(s-A[i]))%mod
    s -= A[i]
    ans = ans % mod

print(ans)

