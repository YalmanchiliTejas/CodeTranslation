n=int(input())
a=[]
for i in range(n):
    a.append(-int(input()))
dp=[10**10 for i in range(n+1)]
import bisect
for i in a:
    idx=bisect.bisect_right(dp,i)
    dp[idx]=i

ans=bisect.bisect_left(dp,10**10)
print(ans)