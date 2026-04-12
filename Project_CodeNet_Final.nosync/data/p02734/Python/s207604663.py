#from collections import deque,defaultdict
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
#R = 10**9 + 7
R = 998244353

def ddprint(x):
  if DBG:
    print(x)

n,s = inm()
a = inl()
dp = [[0]*(s+1) for i in range(n+1)]
for i in range(n):
    for j in range(1,s):
        dp[i+1][j] = dp[i][j]
    for j in range(1,s-a[i]+1):
        if dp[i][j]>0:
            dp[i+1][j+a[i]] = (dp[i+1][j+a[i]]+dp[i][j])%R
    if a[i]<=s:
        dp[i+1][a[i]] = (dp[i+1][a[i]]+i+1)%R
if False and DBG:
    for i in range(n+1):
        ddprint(dp[i])
sm = 0
for i in range(1,n+1):
    sm = (sm+dp[i][s]*(n+1-i))%R
print(sm)
