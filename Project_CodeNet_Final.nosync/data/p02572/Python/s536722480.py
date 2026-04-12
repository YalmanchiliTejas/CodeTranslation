n = int(input())
a = list(map(int,input().split()))
b = a.copy()
for i in range(1,n):
    a[i] += a[i-1]
ans = 0
for i in range(n-1):
    ans += b[i] * (a[-1]-a[i])
mod = 10**9 + 7
print(ans % mod)
