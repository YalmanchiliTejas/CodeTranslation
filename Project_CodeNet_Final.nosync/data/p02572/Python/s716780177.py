N=int(input())
A=list(map(int,input().split(' ')))

AjtoN=sum(A)
Asum=0
for i in range(N):
    AjtoN-=A[i]
    Asum+=A[i]*AjtoN
    Asum=Asum%(10**9+7)

print(Asum)