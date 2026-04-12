import math
import sys
n=int(input())
k=int(input())
s=str(n)
l=len(s)
dp0=[[0 for j in range(k+1)] for i in range(l)]
dp1=[[0 for j in range(k+1)] for i in range(l)]

x=int(s[0])
dp0[0][1]=x-1
dp0[0][0]=1
dp1[0][1]=1
for i in range(1,l):
    x=int(s[i])
    dp0[i][0]=1

    for j in range(1,k+1):
        dp0[i][j]+=dp0[i-1][j-1]*9+dp0[i-1][j]
        if x>0:
            dp0[i][j]+=dp1[i-1][j-1]*(x-1)+dp1[i-1][j]
            dp1[i][j]=dp1[i-1][j-1]
        else:
            dp1[i][j]=dp1[i-1][j]

print(dp0[l-1][k]+dp1[l-1][k])
