N=int(input())
A=list(map(int, input().split()))

MOD=7+10**9
SUM=sum(A)
ans=0

for i in range(N-1):
    SUM-=A[i]
    ans += A[i]*SUM %MOD
print(ans %MOD)