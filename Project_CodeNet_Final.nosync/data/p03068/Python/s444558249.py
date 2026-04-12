# coding: utf-8
# Your code here!

N=int(input())
S=input()
K=int(input())

target=S[K-1]
ans=""

for i in range(N):
    if S[i]==target:
        ans+=target
    else:
        ans+='*'        
print(ans)