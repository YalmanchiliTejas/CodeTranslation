N = int(input())
A = [int(input()) for _ in range(N)]

dp = [-A[0]]
def solve():
    import bisect
    for i in range(1, N):
        a = bisect.bisect_left(dp, -A[i]+0.1) #入れるべき場所
        # print (a)
        if a == len(dp):
            dp.append(-A[i])
        else:
            dp[a] = -A[i]
        # print (dp)
    return len(dp)


print (solve())