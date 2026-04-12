n = int(input())
a = list(map(int, input().split()))

s = sum(a[1:])
ans = 0

for i in range(n - 1):
    ans += a[i] * s
    s -= a[i + 1]
print(ans % (10**9+7))