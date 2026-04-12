N = int(input())
A = list(map(int, input().split()))
MOD = 10**9 + 7
S = sum(A) % MOD
ans = (S ** 2) % MOD
for a in A:
    ans -= a**2
    ans %= MOD

ans *= pow(2, MOD-2, MOD)
ans %= MOD
print(ans)