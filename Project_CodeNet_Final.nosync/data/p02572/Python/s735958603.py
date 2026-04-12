N = int(input())
A = [int(i) for i in input().split()]
MOD = 10 ** 9 + 7

sum_mod = 0
for v in A:
    sum_mod += v
    sum_mod %= MOD

ans = 0
for v in A:
    sum_mod -= v
    if sum_mod < 0:
        sum_mod = MOD + sum_mod
    ans += ((v * sum_mod) % MOD)
    ans %= MOD

print(ans)