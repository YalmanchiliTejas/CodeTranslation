N=int(input())
A=list(map(int, input().split()))

p=10**9+7

SUM=0
for i in range(N):
    SUM+=A[i]
    SUM%=p

ans=0
for i in range(N):
    SUM-=A[i]
    SUM%=p
    ans+=(A[i]*(SUM))%p
    
    ans%=p

print(ans)
#print(SUM)