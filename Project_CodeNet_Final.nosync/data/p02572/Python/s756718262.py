N = int(input())
A = list(map(int, input().split()))

MOD = 1000000007

cum = []

s = 0
for a in A:
    s += a
    cum.append(s)


ans = 0
for i, a in enumerate(A):
    c = a * ((s - cum[i]) % MOD) % MOD
    ans += c % MOD
    ans %= MOD

print(ans)

