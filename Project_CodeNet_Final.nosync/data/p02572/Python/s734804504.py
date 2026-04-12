import math

N=int(input())
A=list(map(int,input().split()))
ans=0
tmp=0

for i in range(N-1):
    tmp+=A[i]
    ans+=tmp*A[i+1]
print(ans%((10**9)+7))