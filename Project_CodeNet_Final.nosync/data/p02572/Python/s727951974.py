MOD = 10**9+7
n = int(input())
a = [int(x) for x in input().split()]

s = sum(a)
ans = 0

for i in range(n):
    s -= a[i]
    ans = (ans + a[i]*s%MOD) % MOD

print(ans)