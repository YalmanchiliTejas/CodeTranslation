import sys
sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))
from collections import defaultdict
def resolve():
    N = ir()
    A = lr()
    dp = defaultdict(lambda: -float('inf'))
    dp[0, 0, 0] = 0
    for i in range(N):
        for j in range(max(i//2-1, 0), i//2+2):
            dp[i+1, j+1, 1] = dp[i, j, 0]+A[i]
            dp[i+1, j, 0] = max(dp[i, j, 0], dp[i, j, 1])
    # print(dp)
    print(max(dp[N, N//2, 1], dp[N, N//2, 0]))
resolve()