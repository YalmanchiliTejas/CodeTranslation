n, s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

lst = [0 for i in range(s+1)]
dp = [lst]
for i in range(n):
    new = [0 for i in range(s+1)]
    new[0] = 1
    if a[i]<=s: new[a[i]] = 1
    for j in range(s+1):
        if j-a[i] >= 0:
            new[j] += dp[-1][j] + dp[-1][j-a[i]]
            new[j] %= mod
        else:
            new[j] += dp[-1][j]
            new[j] %= mod
    dp.append(new)

ans = 0
for i in range(n+1):
    ans += dp[i][-1]
    ans %= mod
print(ans)