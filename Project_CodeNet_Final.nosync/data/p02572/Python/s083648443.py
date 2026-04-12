mod = 10**9 + 7

N = int(input())
A = [int(x) for x in input().split()]
S = sum(A) % mod

ans = 0
for i in range(N):
    S -= A[i]
    if S < 0: S += mod

    ans += S * A[i]
    ans %= mod
print(ans)