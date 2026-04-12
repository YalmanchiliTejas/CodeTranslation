# coding: utf-8
N= int(input())
A=list(map(int,input().split()))

cA = [A[-1]]

MOD = 10**9+7

for i in range(N-1):
    cA.append(cA[-1]+A[-2-i])

ans=0
cA.reverse()


for i in range(N-1):
    ans+=A[i]*cA[i+1]
    ans=ans%MOD
    
print(ans)