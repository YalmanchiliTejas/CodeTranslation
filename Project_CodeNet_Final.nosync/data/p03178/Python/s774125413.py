string = input()
d = int(input())

nums = [int(v) for v in string]
length = len(string) - 1
k = int(string)

M = 10**9 + 7
def mod(v):
    if v >= M:
        return v % M
    return v

dp = [[[None] * 2 for _ in range(d)] for _ in range(length + 2)]
def dfs(i=0, s=0, border=True):
    if dp[i][s][border] is not None:
        return dp[i][s][border]

    if i > length:
        r = int(not bool(s))
        dp[i][s][border] = r
        return r

    cnt = 0
    for n in range(max(9 * (not border), nums[i]) + 1):
        cnt = mod(cnt + dfs(i + 1, (s + n) % d, border and nums[i] == n))
    dp[i][s][border] = cnt
    return cnt
# print(mod(dfs() - 1))

for i in reversed(range(length + 2)):
    for s in reversed(range(d)):
        for border in [False, True]:
            if i > length:
                dp[i][s][border] = int(not bool(s))
                continue

            cnt = 0
            for n in range(max(9 * (not border), nums[i]) + 1):
                cnt = mod(cnt + dp[i + 1][(s + n) % d][border and nums[i] == n])
            dp[i][s][border] = cnt

print(mod(dp[0][0][1] - 1 + M))
