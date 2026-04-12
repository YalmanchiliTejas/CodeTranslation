N=input()
A=list(map(int,input().split()))
ans=0
S=sum(A)
M=10**9+7
for i in A:
    S-=i
    ans+=i*S%M
    ans%=M
print(ans)