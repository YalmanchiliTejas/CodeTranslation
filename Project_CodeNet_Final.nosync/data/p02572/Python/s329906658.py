n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7
ans = 0
v = sum(a)

for i in range(n - 1):
    v -= a[i]
    ans += a[i]*v

print(ans % mod)