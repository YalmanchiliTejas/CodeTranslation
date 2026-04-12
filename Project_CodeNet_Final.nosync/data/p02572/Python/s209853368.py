N=int(input())
A=list(map(int,input().split()))
ans=0
s=sum(A)
for i in range(N-1):
    s-=A[i]
    ans+=(A[i]*(s))%(10**9+7)
print(ans%(10**9+7))
