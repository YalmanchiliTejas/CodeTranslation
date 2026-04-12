MOD = 10 ** 9 + 7

n = int(input())
alst = list(map(int, input().split()))
total = sum(alst)
ans = 0
for a in alst:
    ans += a * (total - a)
    ans %= MOD
ans *= pow(2, MOD - 2, MOD)
ans %= MOD
print(ans)