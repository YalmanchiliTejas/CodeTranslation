import numpy as np

N=int(input())
A=np.array(input().split(" "),dtype=np.int64)

mod=1000000007

# 累積和
s=0
for i in range(N):
    s+=A[i]
    s=s%mod

ans=0
for i in range(N):
    s=s-A[i]
    if(s<0):
        s+=mod
    
    ans+=A[i]*s
    ans=ans%mod
    

print(ans)