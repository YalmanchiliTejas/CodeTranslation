input()
mod=10**9+7
A=list(map(int,input().split()))
S=0
ans=0
for a in A:
    ans=(ans+S*a)%mod
    S+=a
print(ans)