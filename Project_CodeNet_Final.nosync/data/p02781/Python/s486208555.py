#
import sys
import math
import numpy as np
import itertools

# ひとつ入力
n = int(input())
# ひとつ入力
k = int(input())

a=n
p=0
nn=[]
while a>0:
    p+=1
    r=a%10
    nn.insert(0,r)
    a=a//10
#print(p)


dp0=np.zeros((p+1,k+2),dtype="int64")
dp1=np.zeros((p+1,k+2),dtype="int64")
#print(dp0,dp1)
dp1[0][0]=1
for i in range(p):
    for j in range(k+1):
        dp0[i+1][j]    += dp0[i][j] + dp1[i][j] * (nn[i]>0)
        dp0[i+1][j+1]  += dp0[i][j] * 9 + dp1[i][j] * max(nn[i]-1,0)
        dp1[i+1][j]    += dp1[i][j] * (nn[i]==0)
        dp1[i+1][j+1]  += dp1[i][j] * (nn[i]!=0)
        

answer=dp0[p][k]+dp1[p][k]
#print(nn)
#print(dp0,dp1)
print(answer)
