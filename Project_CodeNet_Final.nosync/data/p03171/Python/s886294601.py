import numpy as np
from numba import njit
N=int(input())
a=np.array([int(i) for i in input().split()],dtype=np.int64)
dp=np.full((N,N),-1,dtype=np.int64)
for i in range(N):
    dp[i][i]=a[i]

@njit('i8(i8,i8,i8[:,:],i8[:])', cache=True)
def calc(i,j,dp,a):
    if dp[i][j]!=-1:
        return dp[i][j]
    dp[i][j]=max(a[i]-calc(i+1,j,dp,a),a[j]-calc(i,j-1,dp,a))
    return dp[i][j]

calc(0,N-1,dp,a)
print(dp[0][N-1])
