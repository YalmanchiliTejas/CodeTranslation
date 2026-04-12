# coding: utf-8
# Your code here!
N,K=map(int,input().split())

sum=0

for i in range(K+1,N+1):
    sum+=(N//i)*(i-K)+max(0,N%i-K+1) #バルクと表面
    
if K==0:
    sum-=N
    
print(sum)

