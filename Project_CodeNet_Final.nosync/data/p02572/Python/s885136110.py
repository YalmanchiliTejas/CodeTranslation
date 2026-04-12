MOD1 = 10**9 + 7
MOD = 2 * MOD1
N = int(input())
A = list(map(int, input().split()))

S_n = 0
for a in A:
    S_n += a
    S_n %= MOD

a_i2 = 0
for a in A:
    a_i2 += a*a
    a_i2 %= MOD

d_ans = pow(S_n, 2 , MOD) - a_i2 + MOD
ans = (d_ans // 2) % MOD1
print(ans)