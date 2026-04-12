n=int(input())
a=list(map(int,input().split()))
b=[0]*(n)
ans=0
for i in range(1,n):
    b[i]=(a[i-1]+b[i-1])%1000000007
for i in range(1,n):
    ans+=(b[i]*a[i])%1000000007
print(ans%1000000007)
