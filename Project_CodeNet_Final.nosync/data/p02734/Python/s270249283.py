mod = 998244353

n,s = map(int, input().split())
a = list(map(int, input().split()))
m = 3000
DP = [0]*(m+1)
ans = 0
for ai in a:
    DP[0] += 1
    for j in reversed(range(ai,m+1)):
        DP[j] += DP[j-ai]
        DP[j] %= mod
    ans += DP[s]
    ans %= mod
print(ans)