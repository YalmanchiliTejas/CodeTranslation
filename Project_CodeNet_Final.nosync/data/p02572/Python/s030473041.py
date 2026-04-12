n = int(input())
a = list(map(int, input().split()))
sum = 0
ans = 0
mod = 1000000007
for i in range(n):
    sum+=a[i]
for i in range(n):
    sum-=a[i]
    ans+=(a[i]*(sum%mod))
    ans%=mod
print(int(ans))
