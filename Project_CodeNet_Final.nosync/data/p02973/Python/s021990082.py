n=int(input())
a_list=[int(input()) for i in range(n)]
a_list.reverse()
INF=10**10
dp=[INF]*n
import bisect
for i in range(n):
    a=a_list[i]
    x=bisect.bisect_right(dp,a)
    dp[x]=a
ans=0
for i in range(n):
    if dp[i]!=INF:
        ans=i+1
print(ans)
