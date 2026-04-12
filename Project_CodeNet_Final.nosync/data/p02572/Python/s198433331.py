import itertools
#h,w=map(int,input().split())
#S=[list(map(int,input().split())) for _ in range(h)]
n=int(input())
A=list(map(int,input().split()))
Ar=list(itertools.accumulate(A))
ans=0
for i in range(n-1):
    ans+=A[i]*(Ar[n-1]-Ar[i])
    ans%=10**9+7
print(ans)
