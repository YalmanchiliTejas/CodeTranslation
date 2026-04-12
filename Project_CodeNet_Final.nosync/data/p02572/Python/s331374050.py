MOD = 10**9+7

n = int(input())
a = list(map(int,input().split()))
asum = []
tmp = sum(a)
for i in a:
    tmp -= i
    asum.append(tmp)

ans = 0
for i in range(n):
    ans += a[i]*asum[i] % MOD
print(ans % MOD)