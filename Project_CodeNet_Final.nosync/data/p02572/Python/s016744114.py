import numpy as np
N = int(input())
A = list(map(int ,input().split()))
sum=0
ans=0
for i in range (0,N-1):
  sum=sum+A[i]
  sum=sum%(1000000000+7)
  ans=ans+sum*A[i+1]
  ans=ans%(1000000000+7)
print(ans)