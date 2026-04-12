n=int(input())
A=list(map(int,input().split()))
s=0
m=10**9+7
for i in A:
    s+=i
    s%=m
ans=0
for i in range(n-1):
    s-=A[i]
    if s<0:
        s+=m
    ans+=(A[i]%m)*s
    ans%=m
print(int(ans))