N=int(input())
A=list(map(int,input().split()))
s=sum(A)
ans=0

for ai in A:
    ans+=(ai*(s-ai))
print((ans//2)%(10**9+7))