N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
S = sum(A)%mod
ans = 0

for x in A:
    S -= x
    S %= mod
    ans += S * x
    ans %= mod

ans %= mod
print(ans)