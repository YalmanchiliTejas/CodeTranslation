N=int(input())
*A,=map(int,input().split())
ra=A[::-1]
S=[0]*(N+1)
for i in range(N):
    S[i+1]=S[i]+ra[i]
M=10**9+7

S=S[::-1]
i=0
ans=0
while i<N:
    ans+=A[i]*S[i+1]
    ans%=M
    i+=1
print(ans)