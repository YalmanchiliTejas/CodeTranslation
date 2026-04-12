n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7
b = sum(a)
ans = 0
for i in range(n - 1):
    b -= a[i]
    ans += b * a[i]
    ans %= mod
print(ans)
