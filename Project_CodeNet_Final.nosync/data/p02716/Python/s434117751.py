import sys
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7 # 998244353
input=lambda:sys.stdin.readline().rstrip()
def resolve():
    n = int(input())
    A = list(map(int,input().split()))

    if n & 1 == 0:
        res = -INF
        score = sum(A[::2])
        res = max(res, score)
        for i in range(n-1,-1,-1):
            if i & 1:
                score += A[i]
            else:
                score -= A[i]
                res = max(res, score)
        print(res)
        return

    front_dp = [None] * n
    choose = -INF
    not_choose = 0
    for i in range(1, n, 2):
        choose, not_choose = max(choose, not_choose) + A[i], not_choose + A[i-1]
        front_dp[i] = max(choose, not_choose)

    back_dp = [None] * n
    choose = -INF
    not_choose = 0
    for i in range(n-2, -1, -2):
        choose, not_choose = max(choose, not_choose) + A[i], not_choose + A[i+1]
        back_dp[i] = max(choose, not_choose)

    res = -INF
    for i in range(1, n, 2):
        if i + 2 < n:
            res = max(res, front_dp[i] + back_dp[i+2])

    res = max(res, front_dp[-2])
    res = max(res, back_dp[1])

    print(res)
resolve()