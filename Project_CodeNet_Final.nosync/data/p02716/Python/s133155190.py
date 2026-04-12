import sys,math,copy,queue,itertools,bisect
LI = lambda : [int(x) for x in sys.stdin.readline().split()]
_LI = lambda : [int(x)-1 for x in sys.stdin.readline().split()]
NI = lambda : int(sys.stdin.readline())
MOD = 10**9 + 7
INF = 10**15

N = NI()
A = LI()
ans = 0
if N % 2 == 0:
    for i in range(1,N,2):
        ans += A[i]
    x = ans
    for i in range(0,N,2):
        x = x + A[i] - A[i+1]
        ans = max(ans,x)
else:
    dp = [0 for _ in range(3)]
    for i in range(N):
        ai = A[i]
        if i % 2 == 0:
            dp[1] = max(dp[0],dp[1])
            dp[0] = dp[0] + ai
        if i % 2 == 1:
            dp[2] = max(dp[1],dp[2])
            dp[1] += ai
        if i % 2 == 0 and i > 0:
            dp[2] += ai
    ans = max(dp[1],dp[2])
print (ans)

