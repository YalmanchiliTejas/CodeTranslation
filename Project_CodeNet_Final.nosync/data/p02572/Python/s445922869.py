n = int(input())
a = list(map(int, input().split()))
val = sum(a[1:])

ans = 0
for i in range(n - 1):
    ans += a[i]*val
    ans %= 10**9 + 7
    val -= a[i + 1]
print(ans)