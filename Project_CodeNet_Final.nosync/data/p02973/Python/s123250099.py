import bisect as bs
N = int(input())
A = [int(input()) for _ in range(N)]
def LDS(a):
    N = len(a)
    INF = float("inf")
    dp = [-INF]*N
    dp[N-1] = a[0]
    for i in range(1, N):
        j = bs.bisect_left(dp, a[i])-1
        dp[j] = a[i]
    for i in range(N-1, -1, -1):
        if dp[i] == -INF:
            return N-i-1
    return N
print(LDS(A))