N = int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

S = sum(A)
S %= MOD
ans = 0
for a in A:
    S += MOD
    S -= a
    S %= MOD
    ans += a * S
    ans %= MOD

print(ans)
