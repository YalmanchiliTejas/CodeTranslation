# coding: utf-8
# Your code here!
n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
ans=0
s=[]
sum_a=0
for i in range(n-1):
    sum_a+=A[i]
    ans+=sum_a*A[i+1]
    #s.append(sum_a)
print(ans%mod)
"""
for i in range(len(A)-1):
    for j in range(i+1,len(A)):
        ans+=A[i]*A[j]
        
print(ans%mod)
"""