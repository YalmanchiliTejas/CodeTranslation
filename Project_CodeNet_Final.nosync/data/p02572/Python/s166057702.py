N=int(input())
A=list(map(int,input().split()))
Asum=sum(A)
ans=0
for i in range(len(A)-1):
    Asum-=A[i]
    ans+=A[i]*Asum
print(ans%1000000007)