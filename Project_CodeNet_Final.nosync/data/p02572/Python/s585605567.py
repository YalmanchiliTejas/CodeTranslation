n = int(input())
a = list(map(int, input().split()))

ans = 0
s = sum(a[1:])
for i in range(n - 1):
    ans += a[i] * s
    s -= a[i + 1]

ans %= 10**9 + 7
print(ans)