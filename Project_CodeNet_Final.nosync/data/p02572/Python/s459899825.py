MOD=10**9+7
N=int(input())
A=list(map(int,input().split()))
a_sum=sum(A)%MOD
ans=0
for a in A:
    a_sum-=a%MOD
    ans+=a_sum*a
    ans%=MOD
print(ans)