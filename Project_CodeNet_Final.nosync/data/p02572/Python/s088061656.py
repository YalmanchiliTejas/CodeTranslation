# coding: utf-8
# Your code here!
N = int(input())
A = list(map(int,input().split()))

mod = 1000000007
sm = 0

for i in range(N):
    sm += A[i]
    sm %= mod
    
ans = 0

for i in range(N):
    sm -= A[i]
    if sm < 0:
        sm += mod
        
    ans += A[i]*sm
    ans %=mod
        
print(ans)