N=int(input())
A=list(map(int, input().split()))
MOD=1000000007
s=0
for i in range(1,N):
    s+=A[i]
    s%=MOD

ans=0
for i in range(N-1):
    ans+=A[i]*s
    ans%=MOD
    s-=A[i+1]
    s%=MOD
    
print(ans%MOD)