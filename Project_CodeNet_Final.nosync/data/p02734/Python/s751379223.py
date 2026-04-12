n, s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

dp = [0 for i in range(s+1)]

ans = 0
tmp = [0]

for i, ai in enumerate(a):
    dpn = []
    dp[0] = i + 1
    for j in range(s+1):
        if j - ai >= 0 and dp[j-ai]:
            dpn.append((dp[j] + dp[j-ai]) % mod)
        else:
            dpn.append(dp[j])
    # print(dpn)
    ans = (ans + dpn[s]) % mod
    dp = dpn[:]
print(ans)
