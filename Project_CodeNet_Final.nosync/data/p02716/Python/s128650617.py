
# -*- coding: utf-8 -*-

N=int(input())
As=list(map(int, input().split()))

k=0
k1=As[0]
g=0
for i in range(2,N+1):
    if i%2==1:
        k=max(k+As[i-1],g)
        k1=k1+As[i-1]
    if i%2==0:
        g=max(k1,g+As[i-1])
    #print(k,k1,g)

ans=g if N%2==0 else k
print(ans)