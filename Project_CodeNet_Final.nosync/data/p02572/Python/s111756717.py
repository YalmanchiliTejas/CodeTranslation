MOD = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
s = 0
t = 0
for x in a:
    s += x
    s %= MOD
    t += x * x
    t %= MOD
ans = (s * s - t) * pow(2, MOD-2, MOD) % MOD
print(ans)