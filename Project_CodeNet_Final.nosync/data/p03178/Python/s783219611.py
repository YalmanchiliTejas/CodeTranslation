# from https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2019/0106_educational_dp_3
from itertools import accumulate
#10**9+7
mod=1000000007


k=input()
d=int(input())
dp=[0]*(d+10)
dp2=0

for c in k:
    c=int(c)
    for e in range(d-1,-1,-1):
        dp[e+10]-=dp[e]
    dp[dp2]+=1
    dp[dp2+c]-=1
    dp=list(accumulate(dp))
    for e in range(9,-1,-1):
        dp[e]+=dp[d+e]
        dp[d+e]=0
    for e in range(d):
        dp[e]%=mod
    dp2=(dp2+c)%d
ans=dp[0]-1
if dp2==0:
    ans+=1
print(ans%mod)