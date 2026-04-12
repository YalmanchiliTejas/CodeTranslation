n=int(input())
A=list(map(int,input().split()))
s=0
ans=0
mod=10**9+7

for i in range(n):
    s+=A[i]

for i in range(0,n-1):
    s-=A[i]
    s%=mod
    ans+=(A[i]*s)
    ans%=mod
print(ans%(10**9+7))