n=int(input())
a=list(map(int, input().split()))
mod=10**9+7

ans=sum(a)**2

for i in range(n):
    ans-=a[i]**2
ans=ans//2
print(ans%mod)