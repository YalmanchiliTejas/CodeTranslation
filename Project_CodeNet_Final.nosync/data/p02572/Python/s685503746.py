from itertools import accumulate

p=10**9+7
N=int(input())
A=list(map(int,input().split()))
sum_A=sum(A)

ans=0
for i in range(N):
    sum_A-=A[i]
    ans+=A[i]*sum_A
    ans%=p

print(ans)