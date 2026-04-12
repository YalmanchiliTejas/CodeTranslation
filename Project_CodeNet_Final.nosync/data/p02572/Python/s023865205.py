# -*- coding: utf-8 -*-

N=int(input())
A=list(map(int,input().split()))

S=[0]*N
S[0]=A[0]

for i in range(1,N):
    S[i]=S[i-1]+A[i]

#S=sum(A)

ans=0
for i in range(N):
    ans+=A[i]*(S[i]-A[i])
    ans%=1000000007

print(ans)