n = int(input())
a = [int(x) for x in input().split()]
MOD = 10**9 + 7

suma = [0]

for aa in a:
    suma.append((suma[-1] + aa)%MOD)

ans = 0
for i, aa in enumerate(a[:-1]):
    ans += (aa % MOD) * ((suma[-1] - suma[i+1])%MOD)
    ans %= MOD
print(ans)