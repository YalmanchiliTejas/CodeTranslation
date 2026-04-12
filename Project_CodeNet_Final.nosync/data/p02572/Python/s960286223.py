n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
x = sum(a)-a[0]
ans = 0
for i in range(n-1):
    ans += (a[i]*x)%mod
    x -= a[i+1]
print(ans%mod)