m=10**9+7
n=int(input())
a=[int(i) for i in input().split()]
ans=0 ; s=a[-1]
for i in range(n-2,-1,-1):
    ans=(ans+s*a[i])%m
    s=(s+a[i])%m
print(ans%m)
    