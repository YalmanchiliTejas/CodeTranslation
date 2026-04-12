import sys,bisect
input=sys.stdin.readline
n=int(input())

a=[int(input()) for _ in range(n)]
a.reverse()

dp=[float("inf")]*(n+1)
for b in a:
    idx=bisect.bisect_right(dp,b)
    dp[idx]=b

ans=bisect.bisect_left(dp,float("inf"))

print(ans)
