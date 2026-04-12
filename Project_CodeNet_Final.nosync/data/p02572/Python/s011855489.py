N=int(input())
A=list(map(int,input().split()))
s=sum(A)
res=0
for i in range(N-1):
    s-=A[i]
    res+=A[i]*s
print(res%(10**9+7))