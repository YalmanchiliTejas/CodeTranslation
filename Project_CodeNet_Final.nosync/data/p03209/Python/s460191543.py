# -*- coding: utf-8 -*-
"""
Created on Sun May 19 16:57:17 2019

@author: Yamazaki Kenichi
"""

N, X = map(int,input().split())

dp = [[1,1] for i in range(N+1)]
for i in range(1,N+1):
    dp[i][0] = dp[i-1][0]*2 + 1
    dp[i][1] = dp[i-1][1]*2 + 3

ans = 0
for i in range(2,N+2):
    if X - (dp[-i][1] + 2) >= 0:
        ans += dp[-i][0] + 1
        X -= (dp[-i][1] + 2)
#        print(ans,X,dp[-i])
    else:
        X -= 1
#        print(ans,X,dp[-i])
    if i == N+1 and X >= 1:
        ans += 1
#        print(ans,X,dp[-i])
print(ans)