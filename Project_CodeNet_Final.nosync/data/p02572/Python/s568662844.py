N=int(input())
As=list(map(int,input().split()))

sumA=As[-1]
MOD=10**9+7
ans=0
for n in range(N-1):
    Ai=As[N-2-n]
    ans+=sumA*Ai
    ans%=MOD
    sumA+=Ai
    sumA%=MOD
print(ans)