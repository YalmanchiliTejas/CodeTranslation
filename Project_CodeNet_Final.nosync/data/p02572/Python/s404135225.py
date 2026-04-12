n=int(input())
A=list(map(int,input().split(" ")))

base=10**9+7
s=0
for i in range(1,len(A),1):
    s=(s+A[i])%base
ans=0
for i in range(len(A)-1):
    ans=(ans+(A[i]*s))%base
    s=(s-A[i+1]+base)%base
print(ans)
