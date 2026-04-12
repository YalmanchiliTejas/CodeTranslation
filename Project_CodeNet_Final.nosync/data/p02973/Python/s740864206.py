from bisect import bisect
inf = float('inf')

# 広義単調増加
def LIS(arr):
    N = len(arr)
    dp = [inf] * N
    res = 0
    for a in arr:
        pos = bisect(dp,a)
        dp[pos] = a
        res = max(res, pos + 1)
    return res

N = int(input())
A = [int(input()) for _ in range(N)]

ans = LIS(A[::-1])
print(ans)