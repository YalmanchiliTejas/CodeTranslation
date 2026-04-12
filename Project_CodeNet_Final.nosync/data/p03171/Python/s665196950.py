import numpy as np
n=int(input())
A=np.array(list(map(int,input().split())),dtype='int64')
dp=A.copy()
for i in range(1,n):
    if i%2==0:
        dp=np.maximum(dp[1:]+A[:n-i],dp[:-1]+A[i:])
    else:
        dp=np.minimum(dp[1:]-A[:n-i],dp[:-1]-A[i:])
print(dp[0]*(n%2*2-1))