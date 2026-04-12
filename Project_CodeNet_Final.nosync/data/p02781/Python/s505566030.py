from decimal import*
from fractions import*
import math
import functools

s=input()
k=input()
k=(int)(k)

n=len(s)
dp=[[[0 for mind in range (2)] for j in range(k+5)] for i in range(n+5)]

dp[0][0][0]=1
for i in range(n):
    for j in range(2):
        for cnt in range(k+1):
            pre_num=1
            if(j!=0):
                pre_num=9
            else:
                pre_num=(int)(s[i])
            for digit in range(pre_num+1):
                cur=j
                if(digit<pre_num): 
                    cur=1
                dp[i+1][cnt+(digit!=0)][cur]+=dp[i][cnt][j]
sum=dp[n][k][0]+dp[n][k][1]
print(sum)
