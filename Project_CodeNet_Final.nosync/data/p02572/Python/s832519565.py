n = int(input())
a = list(map(int,input().split()))
ans = sum(a)**2
mod = 10**9 + 7

for i in range(n):
    ans -= a[i]**2
ans //= 2
print(ans%mod)