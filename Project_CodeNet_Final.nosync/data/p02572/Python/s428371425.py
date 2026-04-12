N=int(input())
A=list(map(int,input().split()))
s=sum(A)
ans=0
for i in A[:N-1]:
    s-=i
    ans+=s*i
    ans%=10**9+7
print(ans)