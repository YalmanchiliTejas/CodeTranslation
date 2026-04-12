import sys,queue,math,copy,itertools,bisect,collections,heapq
LI = lambda : [int(x) for x in sys.stdin.readline().split()]
NI = lambda : int(sys.stdin.readline())
N = NI()
a = LI()

dp = [[0] * (N+1) for _ in range(N+1)]

for i in range(N-1,-1,-1):
    for j in range(i+1):
        dp[i][j] = max(a[i-j]-dp[i+1][j],a[N-j-1]-dp[i+1][j+1])

print(dp[0][0])